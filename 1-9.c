// 1-9

for (;;) {
	uret1 = fread(buf, 1, (size_t)block_size, src_fp);
	if (uret1 < (size_t)block_size) {
		if (feof(src_fp) != 0) {
			eof_flag = 1;				// ������ ���̰ų� ������ ��Ʈ�� �о��ٰ� ���⼭ break�ϸ� �б⸦ ���ϴϱ� flag���� set���ش�.
		}
		else {
			printf("error: fread failed (%d)\n", __LINE__);
			return EXIT_FAILURE;
		}
	}

	uret2 = fwrite(buf, 1, uret1, dst_fp);    // uret1 �� ������ŭ ���ڴ�
	if (uret2 < uret1) {					  // ���� (uret2 ��  uret1�� ���ƾ� �Ѵ�)
		printf("error: fwrite failed (%d)\n", __LINE__);
		return EXIT_FAILURE;
	}
	copied += uret2;
	if (eof_flag) break;
}


// 2�� �� -> ��ȿ�����̰� 1����Ʈ�� �д� ����   ex) 10, block_size �� �ϸ�   ��Ȯ�ϰ� �� ����Ʈ�� �о����� �� ���� ����

// �������� stat �̿��ؼ� ������ ��Ȯ�� ũ�⸦ �о read