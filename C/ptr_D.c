// 인텔 ai sw 과정 자료구조 수업 중 ptr 개념 보강 (2024.11.27 ~ 2024.11.29)  

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h> 

 


// ----------------------------------------------------------------------------//

// D6

#if 0

void f(int* p)
{
	p[2] = p[2] * 10;

}
int a[4] = { 1,2,3,4 };
void main(void)
{
	printf("%d\n", a[2]);
	f(a);
	printf("%d\n", a[2]);
}

#endif

// 정답

#if 0

void f(int* p)
{
	p[2] = 30;
}

int a[4] = { 1,2,3,4 };

void main(void)
{
	printf("%d\n", a[2]);
	f(a);
	printf("%d\n", a[2]);
}

#endif


// ----------------------------------------------------------------------------//

// D7

#if 0

void f(int* p)
{
	p[1] = p[1] * 10;
}

int a[4] = { 1,2,3,4 };

void main(void)
{
	printf("%d\n", a[2]);
	f(a + 1);
	printf("%d\n", a[2]);
}

#endif

// 정답

#if 0

void f(int* p)
{
	p[1] = 30;
}

int a[4] = { 1,2,3,4 };

void main(void)
{
	printf("%d\n", a[2]);
	f(a + 1);
	printf("%d\n", a[2]);
}

#endif


// ----------------------------------------------------------------------------//

// D8

#if 0

int* f(void)
{
	static int a[4] = { 1,2,3,4 };

	return a;
}

void main(void)
{
	int x;

	x = f()[2];

	printf("%d\n", x);
}

#endif

// 정답

#if 0

int* f(void)
{
	static int a[4] = { 1,2,3,4 };

	return a;
}

void main(void)
{
	int x;

	x = f()[2];

	printf("%d\n", x);
}

#endif


// ----------------------------------------------------------------------------//

// D9

#if 0

int* f(void)
{
	static int a[4] = { 1,2,3,4 };

	return a - 1;
}

void main(void)
{
	int x;

	x = f()[3];

	printf("%d\n", x);
}

#endif

// 정답

#if 0

int* f(void)
{
	static int a[4] = { 1,2,3,4 };

	return a - 1;
}

void main(void)
{
	int x;

	x = f()[3];

	printf("%d\n", x);
}

#endif