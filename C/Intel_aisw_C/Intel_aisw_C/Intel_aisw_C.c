

// ���� ai sw ���� C��� ���� (2024.11.19 ~ 2024.11.21)  ���� : ȥ�� �����ϴ� C���

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>



// ----------------------------------------------------------------------------//

// 1. �������� �ּҰ� ���� Ȯ��

#if 0

int main()
{
	unsigned int data;
	unsigned int* p32b;
	unsigned short* p16b;
	unsigned char* p8b;

	data = 0x12345678;

	p32b = &data;
	p16b = (unsigned short*)&data;
	p8b = (unsigned char*)&data;

	printf("p32b address: %p, p32b data: %x\n\n", p32b, *p32b);
	printf("p16b address: %p, p16b data: %x\n\n", p16b, *p16b);
	printf("p8b address: %p, p8b data: %x\n\n", p8b, *p8b);

	return 0;
}

#endif


// ----------------------------------------------------------------------------//

// 2. p.82 ���� ���� �� ���

#if 0

int main(void)
{
	int a;
	int b, c;
	double da;
	char ch;

	a = 10;
	b = a;
	c = a + 20;
	da = 3.5;
	ch = 'A';

	printf("���� a�� ��: %d\n", a);
	printf("���� b�� ��: %d\n", b);
	printf("���� c�� ��: %d\n", c);
	printf("���� da�� ��: %1lf\n", da);
	printf("���� ch�� ��: %c\n", ch);

	return 0;

}

#endif


// ----------------------------------------------------------------------------//

// 3. ���� �����ڿ� ���� ������ ��

#if 0

int main(void)
{
	int a = 5, b = 5;
	int pre, post;

	pre = (++a) * 3;
	post = (b++) * 3;

	printf("�ʱ갪a= %d, b= %d\n", a, b);
	printf("������:(++a)*3= %d, ������: (b++)*3=%d\n", pre, post);

	return 0;
}

#endif


// ----------------------------------------------------------------------------//

// 4. ������ ������ ������ Ȯ��

#if 0

int main(void)
{
	int A = 10;
	int* pA = &A;
	char C = 'a';
	char* pC = &C;

	printf("A size: %zd, pA size: %zd", sizeof(A), sizeof(pA));
	printf("A size: %zd, pA size: %zd", sizeof(C), sizeof(pC));
	return 0;
}

#endif


// ----------------------------------------------------------------------------//

// 5. �ݺ��� Ȱ���� ������ ����ϱ�

#if 0

int main(void)
{
	int a, i;

	while (1)
	{

		scanf("%d", &a);
		if (a > 0)
		{
			for (i = 1; i < 10; i++)
			{
				printf("%d*%d=%d\n", a, i, a * i);
			}
		}
		else
		{
			printf("������ �Է����ּ���.");
		}

	}
}

#endif


// ----------------------------------------------------------------------------//

// 6. p.204 �ݺ��� Ȱ�� ���� X�� �׸���

#if 0

int main()
{
	int i, j;
	for (i = 0; i < 5; i++)
	{
		for (j = 0; j < 5; j++)
		{
			if (i == j || i + j == 4) { printf("*"); }
			else printf(" ");
		}
		printf("\n");
	}
}

#endif


// ----------------------------------------------------------------------------//

// 7. 1���� �Ű������� �������� ���� ���ϴ� �Լ�

#if 0

int main(void)
{
	sum(10);
	sum(100);
	return 0;
}

int sum(int x)
{
	int i = 1, tot = 0;

	for (i = 1; i < x + 1; i++)
		tot = tot + i;
	printf("1���� %d������ ���� %d�Դϴ�.\n", x, tot);
}

#endif


// ----------------------------------------------------------------------------//

// 8. p.249 C������ ���ڿ��� ������ �迭�� ó���Ѵ�.

#if 0

int main(void)
{
	char str[80] = "apple jam";

	printf("���� ���ڿ�:%s\n", str);
	printf("���ڿ� �Է�:");
	scanf("%s", str);
	printf(" �Է� �� ���ڿ�: %s\n", str);

	return 0;
}

#endif


// ----------------------------------------------------------------------------//

// 9. p.282 �����͸� �̿��� swap �Լ�

#if 0

void swap(int* pa, int* pb);

int main(void)
{
	int a = 10, b = 20;

	swap(&a, &b);
	printf("a:%d, b:%d\n", a, b);

	return 0;
}

void swap(int* pa, int* pb)
{
	int temp;

	temp = *pa;
	*pa = *pb;
	*pb = temp;
}

#endif


// ----------------------------------------------------------------------------//

// 10. p.284 swao�Լ� ������ ���� a, b�� ������� �ʾұ⿡ ������ ����.

#if 0

void swap(void);

int main(void)
{
	int a = 10, b = 20;

	swap();
	printf("a:%d, b:%d", a, b);

	return 0;

}


void swap(void)
{
	int temp;

	temp = a;
	a = b;
	b = temp;
}

#endif


// ----------------------------------------------------------------------------//

// 11. p.286 C���� call by value�� ������ �Ű������� ���� ����ż� ���޵ȴ�. ���� main�Լ����� ������ ���� a, b�� ���� �ٲ��� �ʴ´�.

#if 0

void swap(int x, int y);

int main(void)
{
	int a = 10, b = 20;

	swap(a, b);
	printf("a:%d, b:%d", a, b);

	return 0;

}

void swap(int x, int y)
{
	int temp;

	temp = x;
	x = y;
	y = temp;
}

#endif


// ----------------------------------------------------------------------------//

// 12. ���� - ����n�� ���� �Է¹ް� 1���� n���� �� ���� 3�� ����� ��쿡�� Buzz�� 5�� ����� ��쿡�� Fizz�� �׸��� 3�� 5�� ������� ��쿡�� FizzBuzz�� ���

#if 0

void fizzBuzz(int num);

int main(void)
{
	int n, i;
	scanf("%d", &n);
	for (i = 1; i < n + 1; i++)
	{
		fizzBuzz(i);
	}
}


void fizzBuzz(int num)
{
	if (num % 3 == 0 && num % 5 == 0)
		printf("fizzBuzz\n");
	else if (num % 3 == 0)
		printf("Fizz\n");
	else if (num % 5 == 0)
		printf("Buzz\n");
	else printf("%d\n", num);

}

#endif


// ----------------------------------------------------------------------------//

// 13. ���� - �Է� ���� ���� ������ ���  (�Ǽ��� �Է½� ó�� ���)

#if 0

int main(void)
{
	double num;
	int a;

	while (1)
	{
		printf("���� ������ �Է��ϼ���.\n");

		scanf("%lf", &num);

		if (num != (int)num) // �Ǽ��� �Է½� ó��
		{
			printf("�Ǽ����� �Է��Ͽ����ϴ�.\n");
			continue;
		}



		if (num > 0)
		{
			int a = (int)num;
			int i;
			for (i = 1; i < 10; i++)
				printf("%d*%d=%d\n", a, i, a * i);
		}

		else
		{
			printf("���� ������ �Է��ϼ̽��ϴ�.\n");
		}
	}

}

#endif


// ----------------------------------------------------------------------------//

// 14. p.320�迭�� �̿��� �ζ� ��ȣ ���� ���α׷�

#if 0

void input_nums(int* lotto_nums);
void print_nums(int* lotto_nums);

int main(void)
{
	int lotto_nums[6];

	input_nums(lotto_nums);
	print_nums(lotto_nums);
	return 0;
}

void input_nums(int* lotto_nums)
{
	int i;
	for (i = 0; i < 6; i++)
	{
		scanf("%d", lotto_nums + i);
	}
}

void print_nums(int* lotto_nums)
{
	int i;
	for (i = 0; i < 6; i++)
	{
		printf("%d\n", lotto_nums[i]);
	}
}

#endif


// ----------------------------------------------------------------------------//

// 15. p.347 ���ڿ��� �ּһ������ Ȯ��

#if 0

int main(void)
{
	printf("%p\n", "apple");		// ���ڿ� = �ּһ�� 
	printf("%p\n", "apple" + 1);
	printf("%c\n", *"apple");		// a
	printf("%c\n", *("apple" + 1));
	printf("%c\n", "apple"[2]);		// ���ڿ��� �迭ó�� ÷�ڸ� ����� �� �ִ�.

	return 0;
}

#endif


// ----------------------------------------------------------------------------//

// 16. p.348 char�����ͷ� ���ڿ� ���

#if 0

int main(void)
{
	char* dessert = "apple";  //���ڿ��� �����Ϸ��� �˾Ƽ� �޸𸮿� ��ġ

	printf("���� �Ľ���%�Դϴ�.\n", dessert);
	dessert = "banana";
	printf("���� �Ľ���%�Դϴ�.\n", dessert);

	return 0;

}

#endif


// ----------------------------------------------------------------------------//

// 17. p.365 ���ڿ� ��ȯ �Լ� strcpy()

#if 0

int main(void)
{
	char str1[80] = "strawberry"; // = �������� �º��� ĳ������ �迭�̳� ĳ���� ������ ������ �־��ش�.
	char str2[80] = "apple";
	char* ps1 = "banana";
	char* ps2 = str2;;

	printf("%s\n", str1);
	strcpy(str1, str2);
	printf("%s\n", str1);

	strcpy(str1, ps1);
	printf("%s\n", str1);

	strcpy(str1, str2);
	printf("%s\n", str1);

	strcpy(str1, "banana");
	printf("%s\n", str1);

	return 0;

}

#endif


// ----------------------------------------------------------------------------//

// 18. p.392 ���������� �ʱ�ȭ ������ �� ���� ����ȴ�.

#if 0

void auto_func(void);
void static_func(void);

int main(void)
{
	int i;

	printf("����\n");
	for (i = 0; i < 3; i++)
	{
		auto_func();
	}

	printf("����\n");
	for (i = 0; i < 3; i++)
	{
		static_func();
	}

	return 0;
}

void auto_func(void)
{
	int a = 0;

	a++;
	printf("%d\n", a);
}

void static_func(void)
{
	static int a = 3; //ó�� ����ɶ��� �ʱ�ȭ �ι�° ���ʹ� ������� �ʴ´�.

	a++;
	printf("%d\n", a);
}

#endif


// ----------------------------------------------------------------------------//

// .

#if 0



#endif