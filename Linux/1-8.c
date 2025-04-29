// 1-8

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

int main(int argc, char **argv)		// argc 인자 갯수, argv 인자 값들을 저장한 배열
{
	int ret, src_fd, dst_fd;
	char c, *src_name, *dst_name;
	unsigned int copied = 0;

	if (argc != 3) {				// 잘못 사용됐을 때
		printf("usage: %s {src file} {dst file}\n", argv[0]);
		return EXIT_FAILURE;
	}
	printf("running %s %s %s\n", argv[0], argv[1], argv[2]);

	src_name = argv[1];
	dst_name = argv[2];

	/* open source file */
	src_fd = open(src_name, O_RDONLY);
	if (src_fd == -1) {
		printf("error: %s (%d)\n", strerror(errno), __LINE__);
		return EXIT_FAILURE;
	}

	/* open destination file */
	dst_fd = open(dst_name, O_WRONLY | O_EXCL | O_CREAT, S_IRUSR | S_IWUSR);	// 파일이 존재하지 않으면 에러, 소유자의 R,W권한 활성화
	if (dst_fd == -1) {
		printf("error: %s (%d)\n", strerror(errno), __LINE__);	// __LINE__   %d 현재 행번호																	
		return EXIT_FAILURE;									// __FILE__   %s 매크로 출력된 파일
	}															// __func__	  %s 매크로가 호출된 함수


	/* copy */
	for (;;) {
		ret = read(src_fd, &c, 1);		// 1바이트짜리 버퍼
		if (ret == -1) {
			printf("error: %s (%d)\n", strerror(errno), __LINE__);
			return EXIT_FAILURE;
		}
		if (ret == 0) break;

		ret = write(dst_fd, &c, 1);
		if (ret == -1) {
			printf("error: %s (%d)\n", strerror(errno), __LINE__);
			return EXIT_FAILURE;
		}							// 파일에 쓰는 거기 때문에 ret가 0인 경우는 생략
		copied++;					// 에러만 아니면 성공이라고 생각하고 짠 코드
	}

	/* close */
	close(src_fd);		// 파일을 열어줬으면 닫아줘야함
	close(dst_fd);		// 근데 여기서는 닫아주지 않아도 크게 문제 없다 (바로 뒤에 프로그램이 끝나니깐)

	printf("%u bytes copied\n", copied);

	return EXIT_SUCCESS;
}
