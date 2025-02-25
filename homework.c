//[EX01 - 09]�� �����϶�.
//[EX01 - 09]�� fread()�� fwrite() �� size�� 1�� �����ϰ� �ִ�.
//size�� block_size��(¥���� ���� ���� block_size ���� ���� �������) �����Ͽ� �����ϵ��� �ڵ带 �����϶�.�̸� ���ؼ��� stat() �Լ��� �̿��Ͽ� ���� ������ ũ�⸦ �ľ��ؾ� �Ѵ�.
//���� ����[EX01 - 09]�� �����ϴ�.

#if 0

#include <errno.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>

#define MAX_BLOCK_SIZE 4096

int main(int argc, char **argv) {
	int block_size;
	size_t uret, copied = 0;
	FILE *src_fp, *dst_fp;
	char *src_name, *dst_name;
	char buf[MAX_BLOCK_SIZE];
	struct stat src_stat;
	size_t remaining;

	if (argc != 4) {
		printf("usage: %s {src file} {dst file} {block size in bytes}\n", argv[0]);
		return EXIT_FAILURE;
	}
	printf("running %s %s %s %s\n", argv[0], argv[1], argv[2], argv[3]);

	src_name = argv[1];
	dst_name = argv[2];
	block_size = atoi(argv[3]);

	if (block_size > MAX_BLOCK_SIZE) {
		printf("error: block size is too big (maximum is %d bytes) (%d)\n",
			MAX_BLOCK_SIZE, __LINE__);
		return EXIT_FAILURE;
	}

	/* Get source file size using stat */
	if (stat(src_name, &src_stat) != 0) {
		printf("error: %s (%d)\n", strerror(errno), __LINE__);
		return EXIT_FAILURE;
	}
	remaining = src_stat.st_size;

	/* open source file */
	src_fp = fopen(src_name, "r");
	if (src_fp == NULL) {
		printf("error: %s (%d)\n", strerror(errno), __LINE__);
		return EXIT_FAILURE;
	}

	/* open destination file */
	dst_fp = fopen(dst_name, "w");
	if (dst_fp == NULL) {
		printf("error: %s (%d)\n", strerror(errno), __LINE__);
		fclose(src_fp);
		return EXIT_FAILURE;
	}

	/* copy */
	while (remaining > 0) {
		size_t read_size =
			(remaining < (size_t)block_size) ? remaining : (size_t)block_size;

		uret = fread(buf, read_size, 1, src_fp);
		if (uret < 1) {
			if (feof(src_fp) != 0) {
				break;
			}
			else {
				printf("error: fread failed (%d)\n", __LINE__);
				fclose(src_fp);
				fclose(dst_fp);
				return EXIT_FAILURE;
			}
		}

		if (fwrite(buf, read_size, 1, dst_fp) < 1) {
			printf("error: fwrite failed (%d)\n", __LINE__);
			fclose(src_fp);
			fclose(dst_fp);
			return EXIT_FAILURE;
		}

		copied += read_size;
		remaining -= read_size;
	}

	/* close */
	fclose(src_fp);
	fclose(dst_fp);

	printf("%lu bytes copied\n", copied);

	return EXIT_SUCCESS;
}


#endif


//�־��� ���α׷��� �����ϴ� ���α׷� prun�� �ۼ��϶�.
//. / prun ls - al �� ���� �����ϸ� prun�� ls - al�� �����ϰ� ���� ���(status)�� ����ؾ� �Ѵ�.
//���α׷� ���� �� fork()�� exec()�� ����Ѵ�.[EX02 - 05]�� �����϶�.
//
//���� ���� ������ ����.
//
//. / prun ls - al
//total 40
//drwxr - xr - x  2 willtek willtek  4096 Jan 24 07:59 .
//drwxr - xr - x 64 willtek willtek  4096 Jan 22 13 : 01 ..
//- rwxr - xr - x  1 willtek willtek 70856 Jan 24 07 : 59 prun
//...
//[922] pid 923 has been terminated with status 0
//
//. / prun xxx yyy
//[922] pid 923 has been terminated with status 1


#if 0

int main(int argc, char **argv)
{
	pid_t pid_temp;
	char *msg = "none";

	if (argc < 2) {
		printf("usage: %s command arguments \n", argv[0]);
		return EXIT_FAILURE;
	}
	printf("[%d] running %s\n", pid = getpid(), argv[0]);

	pid_temp = fork();

	if (pid_temp == -1) {
		printf("[%d] error: %s (%d)\n", pid, strerror(errno), __LINE__);
		return EXIT_FAILURE;
	}
	else if (pid_temp == 0) {
		int ret;
		pid = getpid();
		msg = "this is child";
		printf("[%d] changing process to '%s'\n", pid, argv[1]);

		ret = execvp(argv[1], &argv[1]);
		if (ret == -1)
		{
			printf("[%d] execvp failed: %s\n", pid, strerror(errno));
			return EXIT_FAILURE;
		}
	}


#endif




	//���� �ð��� ��:��:�ʷ� ������Ʈ�ϴ� ������ �ð踦 �ۼ��϶�.
	//./dclock �� ���� �����ϸ� dclock�� ���� �ð��� 1�� �������� ��:��:�ʷ� ����Ѵ�.
	//[EX03-02]�� �����Ѵ�. date ����� Ȱ���ϸ� �ǰ� 1�� �������� ������Ʈ�ϱ� ���� ���� ����(for(;;))�� sleep(1)�� ����� �� �ִ�.
	//
	//���� ���� ������ ����.
	//./dclock
	//08:10:59
	//08:11:00
	//08:11:01


#if 0

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

	int main(void)
	{
		char buf[9];

		for (;;) {
			FILE *fp = popen("/bin/date +%T", "r");
			if (fp == NULL) {
				perror("popen failed");
				return EXIT_FAILURE;
			}

			if (fgets(buf, sizeof(buf), fp) == NULL) {
				perror("fgets failed");
				pclose(fp);
				return EXIT_FAILURE;
			}

			printf("%s\n", buf);

			fflush(stdout);

			pclose(fp);

			sleep(1);
		}

		return EXIT_SUCCESS;
	}



#endif



	//[EX03-10]�� �����Ͽ�, ���� �޸𸮸� �̿��Ͽ� �����͸� �ְ� �޴� sender�� receiver�� �ۼ��϶�.
	//sender�� receiver�� �Ʒ��� ���� ����ü�� �̿��Ͽ� �����͸� ��ȯ�Ѵ�.
	//struct shm_buf {
	//    int sent;
	//    char data[64];
	//}
	//sender�� ���� �޸𸮸� �о� sent�� 0�̸� data�� ���ڿ��� ���� sent�� 1�� ����.
	//�̶�, data�� ���� ���ڿ��� sh001���� sh100�̴�. (sh001, sh002, sh003, ..., sh099, sh100 ���̴�)
	//int i=1; sprintf(shmbuf->data, ��sh%03d��, i); �� ���� �ϸ� shmbuf->data�� ��sh001���� ����.
	//receiver�� ���� �޸𸮸� �о� sent�� 1�̸� data�� �о� ȭ�鿡 ����ϰ� sent�� 0�� ����.
	//sender�� receiver���� ������ �� ���� ���ڿ��� ��� �����ؾ� �Ѵ�.
	//���� �޸� ���� �� ��������� ��ȣ�ؾ� �Ѵ�.
	//
	//���� ���� ������ ����.
	//./sender &
	//./receiver
	//sh001
	//sh002
	//sh003
	//...
	//sh099
	//sh100


#if 0

// shm.h

#define KEY_SHM 0x2223

	struct shm_buf {
		int sent;
		char data[64];
	};


	// sender.c

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <sys/sem.h>
#include <sys/time.h>

#include "sem.h"
#include "shm.h"

	pid_t pid;

	int main(int argc, char **argv)
	{
		int ret;
		int id_shm;
		struct shm_buf *shmbuf;
		int i;
		int id_sem;
		struct sembuf sops_dec[1] = { {0, -1, SEM_UNDO} };
		struct sembuf sops_inc[1] = { {0, 1, SEM_UNDO} };

		if (argc != 1) {
			printf("usage: %s\n", argv[0]);
			return EXIT_FAILURE;
		}
		printf("[%d] running %s\n", pid = getpid(), argv[0]);

		id_sem = semget((key_t)KEY_SEM, 1, 0666 | IPC_CREAT);
		if (id_sem == -1) {
			printf("[%d] error: %s (%d)\n", pid, strerror(errno), __LINE__);
			return EXIT_FAILURE;
		}

		id_shm = shmget((key_t)KEY_SHM, sizeof(struct shm_buf), 0666 | IPC_CREAT);
		if (id_shm == -1) {
			printf("[%d] error: %s (%d)\n", pid, strerror(errno), __LINE__);
			return EXIT_FAILURE;
		}

		shmbuf = shmat(id_shm, (void *)0, 0);
		if (shmbuf == (struct shm_buf *) - 1) {
			printf("[%d] error: %s (%d)\n", pid, strerror(errno), __LINE__);
			return EXIT_FAILURE;
		}

		for (i = 1; i <= 100; ) {
			ret = semop(id_sem, sops_dec, 1);
			if (ret == -1) {
				printf("[%d] error: %s (%d)\n", pid, strerror(errno), __LINE__);
				return EXIT_FAILURE;
			}

			if (shmbuf->sent == 0) {
				sprintf(shmbuf->data, "sh%03d", i);
				shmbuf->sent = 1;
				i++;
			}

			ret = semop(id_sem, sops_inc, 1);
			if (ret == -1) {
				printf("[%d] error: %s (%d)\n", pid, strerror(errno), __LINE__);
				return EXIT_FAILURE;
			}
		}

		ret = shmdt(shmbuf);
		if (ret == -1) {
			printf("[%d] error: %s (%d)\n", pid, strerror(errno), __LINE__);
			return EXIT_FAILURE;
		}

		printf("[%d] terminted\n", pid);

		return EXIT_SUCCESS;
	}

	// receiver.c

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <sys/sem.h>

#include "shm.h"
#include "sem.h"

	pid_t pid;

	int main(int argc, char **argv)
	{
		int ret, i;
		int id_shm;
		struct shm_buf *shmbuf;
		int id_sem;
		struct sembuf sops_dec[1] = { {0, -1, SEM_UNDO} };
		struct sembuf sops_inc[1] = { {0, 1, SEM_UNDO} };

		if (argc != 1) {
			printf("usage: %s\n", argv[0]);
			return EXIT_FAILURE;
		}
		printf("[%d] running %s\n", pid = getpid(), argv[0]);

		id_sem = semget((key_t)KEY_SEM, 1, 0666 | IPC_CREAT);
		if (id_sem == -1) {
			printf("[%d] error: %s (%d)\n", pid, strerror(errno), __LINE__);
			return EXIT_FAILURE;
		}

		id_shm = shmget((key_t)KEY_SHM, sizeof(struct shm_buf), 0666 | IPC_CREAT);
		if (id_shm == -1) {
			printf("[%d] error: %s (%d)\n", pid, strerror(errno), __LINE__);
			return EXIT_FAILURE;
		}

		shmbuf = shmat(id_shm, (void *)0, 0);
		if (shmbuf == (struct shm_buf *) - 1) {
			printf("[%d] error: %s (%d)\n", pid, strerror(errno), __LINE__);
			return EXIT_FAILURE;
		}

		for (i = 1; i <= 100; ) {
			ret = semop(id_sem, sops_dec, 1);
			if (ret == -1) {
				printf("[%d] error: %s (%d)\n", pid, strerror(errno), __LINE__);
				return EXIT_FAILURE;
			}

			if (shmbuf->sent == 1) {
				printf("%s\n", shmbuf->data);
				shmbuf->sent = 0;
				i++;
			}

			ret = semop(id_sem, sops_inc, 1);
			if (ret == -1) {
				printf("[%d] error: %s (%d)\n", pid, strerror(errno), __LINE__);
				return EXIT_FAILURE;
			}
		}

		ret = shmdt(shmbuf);
		if (ret == -1) {
			printf("[%d] error: %s (%d)\n", pid, strerror(errno), __LINE__);
			return EXIT_FAILURE;
		}

		printf("[%d] terminted\n", pid);

		return EXIT_SUCCESS;
	}


#endif