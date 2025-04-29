// 인텔 ai sw 과정 자료구조 수업 중 ptr 개념 보강 (2024.11.27 ~ 2024.11.29)  

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h> 




// ----------------------------------------------------------------------------//

// E0

// 답안과 동일
#if 0

int x[4] = { 1,2,3,4 };    //3->30

void main(void)
{
	int* a[4] = { x + 3, x + 2, x + 1, x };

	printf("%d\n", x[2]);

	a[3][2] = 30;

	printf("%d\n", x[2]);
}

#endif



// ----------------------------------------------------------------------------//

// E1

// 문제

#if 0

#include <stdio.h>

void draw_pixel(int y, int x, int value, p) // 매개변수 완성하기
{
	p[y][x] = value;
}

void main(void)
{
	int a[2][3] = { 1,2,3,4,5,6 };

	printf("%d\n", a[1][2]);
	draw_pixel(1, 2, 10, a);
	printf("%d\n", a[1][2]);
}

출력예시
6
10	// 배열의 마지막 원소를 6에서 10으로 바꿔야 한다는 뜻

#endif

// 정답

#if 0

void draw_pixel(int y, int x, int value, int(*p)[3]) // 이차원 배열을 전달하기 위한 매개변수 
{													 // int[3]을 가리키는 포인터
	p[y][x] = value;
}

void main(void)
{
	int a[2][3] = { 1,2,3,4,5,6 };

	printf("%d\n", a[1][2]);
	draw_pixel(1, 2, 10, a);
	printf("%d\n", a[1][2]);
}

#endif



// ----------------------------------------------------------------------------//

// E2

//문제

#if 0

func(void)   // 2차원 배열을 반환  자료형을 그에 맞춰줘야 한다
{
	static int a[3][4] = { 1,2,3,4,5,6,7,8,9,10,11,12 };
	return a;
}

void main(void)
{
	printf("%d\n", func());
}

출력예시
7  //a[1][2] 가 출력돼야 한다

#endif

// 정답

#if 0

int(*func(void))[4]  // return type of func is ptr point to arr of four int  요소가 넷인 인티저 배열을 가리키는 포인터가 반환타입
{
	static int a[3][4] = { 1,2,3,4,5,6,7,8,9,10,11,12 };
	return a;
}

void main(void)
{
	printf("%d\n", func()[1][2]);
}


#endif



// ----------------------------------------------------------------------------//

// E3

//문제

#if 0

void f()		// 매개변수 완성하기
{
	// 함수 완성하기  
}

int a[4] = { 1,2,3,4 };

void main(void)
{
	printf("%d\n", a[2]);
	f(&a);						// 매개변수를 배열 a의 주소로 해서 호출, 즉 매개변수가 배열의 주소형이어야 한다
	printf("%d\n", a[2]);		// 배열이 온전히 배열로 다루어질때    1. &배열명   2. sizeof(배열명)
}

출력예시
3
30

#endif

// 정답

#if 0

void f(int(*p)[4])     // int(*p)[4]  int[4]를 카리키는 포인터(o)   // int *p[4]면 포인터의 배열이 됨(x)
{
	p[0][2] = 30;
}

int a[4] = { 1,2,3,4 };

void main(void)
{
	printf("%d\n", a[2]);
	f(&a);
	printf("%d\n", a[2]);
}

출력예시
3
30			// 매개변수로 배열a의 주소값을 전달해줘야 한다

#endif



// ----------------------------------------------------------------------------//

// E4

// 문제

#if 0

void f()			// 아래의 함수 호출시의 인수를 보고 함수 완성
{

}

int a[4] = { 1,2,3,4 };

void main(void)
{
	printf("%d\n", a[2]);
	f(&a + 1);				// 배열의 주소에 +1 한 값을 인수로 주었다  주소 연산자 배열이 온전히 배열로 다루어지는 경우에 해당
	printf("%d\n", a[2]);
}

출력예시
3
30

#endif

// 정답

#if 0

void f(int(*p)[4])
{
	p[-1][2] = 30;  // 세번째 원소를 꺼내야하는데 매개변수를 배열뒤의 배열만큼의 주소를 매개변수로 받았다
}					// [-1] 인덱싱으로 배열 a로 돌아온 뒤 꺼내주면 된다

int a[4] = { 1,2,3,4 };

void main(void)
{
	printf("%d\n", a[2]);
	f(&a + 1);
	printf("%d\n", a[2]);
}

#endif

