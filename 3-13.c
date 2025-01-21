// file_client.c

int main(int argc, char **argv)
{
	int ret;
	int id_msg;
	struct msg_buf msgbuf;

	if (argc != 2) {
		printf("usage: %s {file name}\n", argv[0]);
		return EXIT_FAILURE;
	}
	printf("[%d] running %s %s\n", pid = getpid(), argv[0], argv[1]);

	if (strlen(argv[1]) >= MAX_FNAME) {
		printf("[%d] error: maximum file length is %d\n", pid, MAX_FNAME);
		return EXIT_FAILURE;
	}

	/* Implement code */

	id_msg = msgget((key_t)KEY_MSG, 0666 | IPC_CREAT);
	if (id_msg == -1) {
		printf("[%d] error: %s (%d)\n", pid, strerror(errno), __LINE__);
		return EXIT_FAILURE;
	}

	msgbuf.mtype = MTYPE_C2S;
	strcpy(msgbuf.fname, argv[1]);
	msgbuf.pid = pid;

	ret = msgsnd(id_msg, (void *)&msgbuf, sizeof(struct msg_buf) - sizeof(long), 0);
	if (ret == -1) {
		printf("[%d] error: %s (%d)\n", pid, strerror(errno), __LINE__);
		return EXIT_FAILURE;
	}

	ret = msgrcv(id_msg, (void *)&msgbuf, sizeof(struct msg_buf) - sizeof(long), pid, 0);
	if (ret == -1) {
		printf("[%d] error: %s (%d)\n", pid, strerror(errno), __LINE__);
		return EXIT_FAILURE;
	}

	if (msgbuf.valid) {
		printf("[%d] %s: size = %ld bytes\n", pid, argv[1], msgbuf.size);
		printf("[%d] %s: mode = %#o\n", pid, argv[1], msgbuf.mode);
	}
	else {
		printf("[%d] %s: invalid file\n", pid, argv[1]);
	}

	printf("[%d] terminted\n", pid);

	return EXIT_SUCCESS;
}


// file _server.c

pid_t pid;

int main(int argc, char **argv)
{
	int ret;
	int id_msg;
	struct msg_buf msgbuf;
	struct stat statb;

	if (argc != 1) {
		printf("usage: %s\n", argv[0]);
		return EXIT_FAILURE;
	}
	printf("[%d] running %s\n", pid = getpid(), argv[0]);

	id_msg = msgget((key_t)KEY_MSG, 0666 | IPC_CREAT);
	if (id_msg == -1) {
		printf("[%d] error: %s (%d)\n", pid, strerror(errno), __LINE__);
		return EXIT_FAILURE;
	}

	for (;;) {
		ret = msgrcv(id_msg, (void *)&msgbuf, sizeof(struct msg_buf) - sizeof(long), MTYPE_C2S, 0);
		if (ret == -1) {
			printf("[%d] error: %s (%d)\n", pid, strerror(errno), __LINE__);
			return EXIT_FAILURE;
		}

		if (stat(msgbuf.fname, &statb) == -1) {
			msgbuf.valid = 0;
		}
		else {
			msgbuf.valid = 1;
			msgbuf.size = statb.st_size;
			msgbuf.mode = statb.st_mode;
		}
		msgbuf.mtype = msgbuf.pid;

		ret = msgsnd(id_msg, (void *)&msgbuf, sizeof(struct msg_buf) - sizeof(long), 0);
		if (ret == -1) {
			printf("[%d] error: %s (%d)\n", pid, strerror(errno), __LINE__);
			return EXIT_FAILURE;
		}
	}

	printf("[%d] terminted\n", pid);

	return EXIT_SUCCESS;
}
