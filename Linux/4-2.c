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

void *thread_func1(void *arg)		// func1과 func2 다른 부분 1, 2 밖에 없음(이해를 돕기 위해 두개 만듦) 사실상 하나의 함수만 만들고 두개의 스레드를 생성해도 괜찮다.
{
	int i, temp, count = 0;

	printf("[%d] thread1 started with arg \"%d\"\n", pid, *(int *)arg);
	for (i = 0; i < *(int *)arg; i++) {
		temp = g_count;				// 경합조건(race condition  ++연산은 두 가지 작업을 동시에 하는 연산이다. 그 두 작업이 원자적이지 않기에
		usleep(1);					// 두 스레드가 동시에 g_count++ 연산을 하면 g_count의 값은 1만 올라가게 된다. 이를 방지하기 위해 temp를 사용했다.
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
	printf("[%d] all threads terminated (g_count = %d)\n", pid, g_count);	// temp로 경합조건을 해결하려 했지만 동기화 문제가 완전히
																			// 해결된 것은 아님 따라서 20000이 아닌 다른 값이 출력된다.
	printf("[%d] terminted\n", pid);

	return EXIT_SUCCESS;
}
