

// 인텔 ai sw 과정 C언어 수업 (2024.11.19 ~ 2024.11.21)  교재 : 혼자 공부하는 C언어

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>



// ----------------------------------------------------------------------------//

// 1. 변수들의 주소값 직접 확인

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

// 2. p.82 예제 변수 값 출력

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

	printf("변수 a의 값: %d\n", a);
	printf("변수 b의 값: %d\n", b);
	printf("변수 c의 값: %d\n", c);
	printf("변수 da의 값: %1lf\n", da);
	printf("변수 ch의 값: %c\n", ch);

	return 0;

}

#endif


// ----------------------------------------------------------------------------//

// 3. 전위 연산자와 후위 연산자 비교

#if 0

int main(void)
{
	int a = 5, b = 5;
	int pre, post;

	pre = (++a) * 3;
	post = (b++) * 3;

	printf("초깃값a= %d, b= %d\n", a, b);
	printf("전위형:(++a)*3= %d, 후위형: (b++)*3=%d\n", pre, post);

	return 0;
}

#endif


// ----------------------------------------------------------------------------//

// 4. 포인터 변수의 사이즈 확인

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

// 5. 반복문 활용한 구구단 출력하기

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
			printf("정수를 입력해주세요.");
		}

	}
}

#endif


// ----------------------------------------------------------------------------//

// 6. p.204 반복문 활용 별로 X자 그리기

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

// 7. 1부터 매개변수의 값까지의 합을 구하는 함수

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
	printf("1부터 %d까지의 합은 %d입니다.\n", x, tot);
}

#endif


// ----------------------------------------------------------------------------//

// 8. p.249 C언어에서는 문자열을 문자형 배열로 처리한다.

#if 0

int main(void)
{
	char str[80] = "apple jam";

	printf("최초 문자열:%s\n", str);
	printf("문자열 입력:");
	scanf("%s", str);
	printf(" 입력 후 문자열: %s\n", str);

	return 0;
}

#endif


// ----------------------------------------------------------------------------//

// 9. p.282 포인터를 이용한 swap 함수

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

// 10. p.284 swao함수 내에서 변수 a, b는 선언되지 않았기에 오류가 난다.

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

// 11. p.286 C언어는 call by value기 때문에 매개변수에 값이 복사돼서 전달된다. 따라서 main함수에서 선언한 변수 a, b의 값이 바뀌지 않는다.

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

// 12. 과제 - 변수n에 수를 입력받고 1부터 n까지 그 수가 3의 배수인 경우에는 Buzz를 5의 배수인 경우에는 Fizz를 그리고 3과 5의 공배수인 경우에는 FizzBuzz를 출력

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

// 13. 과제 - 입력 받은 수의 구구단 출력  (실수값 입력시 처리 방법)

#if 0

int main(void)
{
	double num;
	int a;

	while (1)
	{
		printf("양의 정수를 입력하세요.\n");

		scanf("%lf", &num);

		if (num != (int)num) // 실수값 입력시 처리
		{
			printf("실수값을 입력하였습니다.\n");
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
			printf("음의 정수를 입력하셨습니다.\n");
		}
	}

}

#endif


// ----------------------------------------------------------------------------//

// 14. p.320배열을 이용한 로또 번호 생성 프로그램

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

// 15. p.347 문자열이 주소상수임을 확인

#if 0

int main(void)
{
	printf("%p\n", "apple");		// 문자열 = 주소상수 
	printf("%p\n", "apple" + 1);
	printf("%c\n", *"apple");		// a
	printf("%c\n", *("apple" + 1));
	printf("%c\n", "apple"[2]);		// 문자열에 배열처럼 첨자를 사용할 수 있다.

	return 0;
}

#endif


// ----------------------------------------------------------------------------//

// 16. p.348 char포인터로 문자열 사용

#if 0

int main(void)
{
	char* dessert = "apple";  //문자열은 컴파일러가 알아서 메모리에 배치

	printf("오늘 후식은%입니다.\n", dessert);
	dessert = "banana";
	printf("내일 후식은%입니다.\n", dessert);

	return 0;

}

#endif


// ----------------------------------------------------------------------------//

// 17. p.365 문자열 교환 함수 strcpy()

#if 0

int main(void)
{
	char str1[80] = "strawberry"; // = 연산자의 좌변은 캐릭터형 배열이나 캐릭터 포인터 변수를 넣어준다.
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

// 18. p.392 정적변수의 초기화 구문은 한 번만 실행된다.

#if 0

void auto_func(void);
void static_func(void);

int main(void)
{
	int i;

	printf("지역\n");
	for (i = 0; i < 3; i++)
	{
		auto_func();
	}

	printf("정적\n");
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
	static int a = 3; //처음 실행될때만 초기화 두번째 부터는 수행되지 않는다.

	a++;
	printf("%d\n", a);
}

#endif


// ----------------------------------------------------------------------------//

// .

#if 0



#endif