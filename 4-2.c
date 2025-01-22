#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>
#include <fcntl.h>
#include <sys/types.h>
#include <pthread.h>

pid_t pid;
int g_count;

void *thread_func1(void *arg)		// func1�� func2 �ٸ� �κ� 1, 2 �ۿ� ����(���ظ� ���� ���� �ΰ� ����) ��ǻ� �ϳ��� �Լ��� ����� �ΰ��� �����带 �����ص� ������.
{
	int i, temp, count = 0;

	printf("[%d] thread1 started with arg \"%d\"\n", pid, *(int *)arg);
	for (i = 0; i < *(int *)arg; i++) {
		temp = g_count;				// ��������(race condition  ++������ �� ���� �۾��� ���ÿ� �ϴ� �����̴�. �� �� �۾��� ���������� �ʱ⿡
		usleep(1);					// �� �����尡 ���ÿ� g_count++ ������ �ϸ� g_count�� ���� 1�� �ö󰡰� �ȴ�. �̸� �����ϱ� ���� temp�� ����ߴ�.
		g_count = ++temp;
		count++;
		usleep(2);
	}

	printf("[%d] thread1 counted %d\n", pid, count);
	pthread_exit(NULL);
}

void *thread_func2(void *arg)
{
	int i, temp, count = 0;

	printf("[%d] thread2 started with arg \"%d\"\n", pid, *(int *)arg);
	for (i = 0; i < *(int *)arg; i++) {
		temp = g_count;
		usleep(1);
		g_count = ++temp;
		count++;
		usleep(2);
	}

	printf("[%d] thread2 counted %d\n", pid, count);
	pthread_exit(NULL);
}

int main(int argc, char **argv)
{
	pthread_t thread_id1, thread_id2;
	int ret;
	int n = 10000;

	if (argc != 1) {
		printf("usage: %s\n", argv[0]);
		return EXIT_FAILURE;
	}
	printf("[%d] running %s\n", pid = getpid(), argv[0]);

	printf("[%d] creating thread (g_count = %d)\n", pid, g_count);
	ret = pthread_create(&thread_id1, NULL, thread_func1, &n);
	if (ret != 0) {
		printf("[%d] error: %d (%d)\n", pid, ret, __LINE__);
		return EXIT_FAILURE;
	}
	ret = pthread_create(&thread_id2, NULL, thread_func2, &n);
	if (ret != 0) {
		printf("[%d] error: %d (%d)\n", pid, ret, __LINE__);
		return EXIT_FAILURE;
	}

	printf("[%d] waiting to join with a terminated thread\n", pid);
	ret = pthread_join(thread_id1, NULL);
	if (ret != 0) {
		printf("[%d] error: %d (%d)\n", pid, ret, __LINE__);
		return EXIT_FAILURE;
	}
	ret = pthread_join(thread_id2, NULL);
	if (ret != 0) {
		printf("[%d] error: %d (%d)\n", pid, ret, __LINE__);
		return EXIT_FAILURE;
	}
	printf("[%d] all threads terminated (g_count = %d)\n", pid, g_count);	// temp�� ���������� �ذ��Ϸ� ������ ����ȭ ������ ������
																			// �ذ�� ���� �ƴ� ���� 20000�� �ƴ� �ٸ� ���� ��µȴ�.
	printf("[%d] terminted\n", pid);

	return EXIT_SUCCESS;
}
