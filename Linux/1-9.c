// 1-9

for (;;) {
	uret1 = fread(buf, 1, (size_t)block_size, src_fp);
	if (uret1 < (size_t)block_size) {
		if (feof(src_fp) != 0) {
			eof_flag = 1;				// 파일의 끝이거나 자투리 비트만 읽었다고 여기서 break하면 읽기를 못하니깐 flag값만 set해준다.
		}
		else {
			printf("error: fread failed (%d)\n", __LINE__);
			return EXIT_FAILURE;
		}
	}

	uret2 = fwrite(buf, 1, uret1, dst_fp);    // uret1 즉 읽은만큼 쓰겠다
	if (uret2 < uret1) {					  // 에러 (uret2 가  uret1과 같아야 한다)
		printf("error: fwrite failed (%d)\n", __LINE__);
		return EXIT_FAILURE;
	}
	copied += uret2;
	if (eof_flag) break;
}


// 2번 줄 -> 비효율적이게 1바이트씩 읽는 이유   ex) 10, block_size 로 하면   정확하게 몇 바이트를 읽었는지 알 수가 없다

// 도전과제 stat 이용해서 파일의 정확한 크기를 읽어서 read