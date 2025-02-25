//[EX01 - 09]를 수정하라.
//[EX01 - 09]는 fread()와 fwrite() 시 size를 1로 설정하고 있다.
//size를 block_size로(짜투리 읽을 때는 block_size 보다 작은 사이즈로) 설정하여 동작하도록 코드를 수정하라.이를 위해서는 stat() 함수를 이용하여 원본 파일의 크기를 파악해야 한다.
//실행 예는[EX01 - 09]와 동일하다.

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


//주어진 프로그램을 실행하는 프로그램 prun을 작성하라.
//. / prun ls - al 과 같이 실행하면 prun은 ls - al을 실행하고 실행 결과(status)를 출력해야 한다.
//프로그램 실행 시 fork()와 exec()를 사용한다.[EX02 - 05]를 참조하라.
//
//실행 예는 다음과 같다.
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




	//현재 시간을 시:분:초로 업데이트하는 디지털 시계를 작성하라.
	//./dclock 과 같이 실행하면 dclock은 현재 시간을 1초 간격으로 시:분:초로 출력한다.
	//[EX03-02]를 참조한다. date 명령을 활용하면 되고 1초 간격으로 업데이트하기 위해 무한 루프(for(;;))와 sleep(1)을 사용할 수 있다.
	//
	//실행 예는 다음과 같다.
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



	//[EX03-10]을 참조하여, 공유 메모리를 이용하여 데이터를 주고 받는 sender와 receiver를 작성하라.
	//sender와 receiver는 아래와 같은 구조체를 이용하여 데이터를 교환한다.
	//struct shm_buf {
	//    int sent;
	//    char data[64];
	//}
	//sender는 공유 메모리를 읽어 sent가 0이면 data에 문자열을 쓰고 sent에 1을 쓴다.
	//이때, data에 쓰는 문자열은 sh001부터 sh100이다. (sh001, sh002, sh003, ..., sh099, sh100 순이다)
	//int i=1; sprintf(shmbuf->data, “sh%03d”, i); 와 같이 하면 shmbuf->data에 “sh001”이 들어간다.
	//receiver는 공유 메모리를 읽어 sent가 1이면 data를 읽어 화면에 출력하고 sent에 0을 쓴다.
	//sender는 receiver에게 가능한 한 빨리 문자열을 모두 전송해야 한다.
	//공유 메모리 접근 시 세마포어로 보호해야 한다.
	//
	//실행 예는 다음과 같다.
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