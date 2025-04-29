// 인텔 ai sw 과정 자료구조 수업 중 ptr 개념 보강 (2024.11.27 ~ 2024.11.29)  

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h> 



// ----------------------------------------------------------------------------//

// E5

// 문제 - '배열 주소'의 함수 리턴 
// f 함수를 실행하여 a[2]값 3이 x에 저장되도록 코드를 완성하라

#if 0

#include <stdio.h> 

f(void)
{
    static int a[4] = { 1,2,3,4 };

    return &a;
}

void main(void)
{
    int x;

    x =   // <-

        printf("%d\n", x);
}

#endif

// 정답

#if 0

int(*f(void))[4] // 출제의도는 배열 주소(int 4개를 원소로 갖는)를 반환하는 것   따라서 int 넷을 원소로 갖는 배열의 포인터가 반환 타입이 된다.
{
	static int a[4] = { 1,2,3,4 }; // static으로 배열 수명을 프로그램 전체로 확장

	return &a;  // 배열의 주소 반환  &연산자는 배열이 오롯이 배열 전체로서 다루어지는 두 경우 중 하나
}

void main(void)
{
	int x;

	x = f()[0][2];  // a가 (int 넷을 원소로 갖는 배열) 포인터이기 때문에 f()[0] 이 배열 a의 첫 원소의 주소가 된다.
					// 그리고 그 타입은 int * 타입의 포인터이므로, 배열처럼 인덱싱할 수 있게된다.
	printf("%d\n", x);
}


#endif



// ----------------------------------------------------------------------------//

// E6

// 문제 - 배열 주소의 함수 리턴
// f 함수를 실행하여 a[2]값 3이 x에 저장되도록 코드를 완성하라
#if 0

#include <stdio.h> 

f(void)   // <- 반환형 완성
{
    static int a[4] = { 1,2,3,4 };

    return &a - 1;		// int 하나가 아니라   int 배열[4] 만큼 앞으로 간거임
}

void main(void)
{
    int x;

    x =  //  <-

        printf("%d\n", x);
}

#endif

// 정답

x = f()[1][2];	// 첫 번째 인덱스로 배열a를 접근 두 번째 인덱스로 세번째 원소 접근







// ----------------------------------------------------------------------------//

// E7

// 문제 - 함수에 함수를 전달

#if 0

int add(int a, int b)
{
    return a + b;
}

int sub(int a, int b)
{
    return a - b;
}

void func()  // <-
{
    printf("%d\n", p(3, 4));
}

void main(void)
{
    func(add);
    func(sub);
}


#endif

// 정답

#if 0

void func(int(*p)(int, int)) // 포인터인데 int 두개를 매개변수로 갖고 int를 반환하는 함수 포인터

#endif



// ----------------------------------------------------------------------------//

// E8 

// 문제 - 단일 포인터
#if 0

#include <stdio.h>

void Swap(p, q)  // <-
{

				 // <-
}

void main(void)
{
    int a = 10, b = 20;

    printf("Before : %d %d\n", a, b);
    Swap(, );							 // <-
    printf("After : %d %d\n", a, b);
}

#endif

// 정답

#if 0

void Swap(int* p, int* q)
{
	int tmp = *p;
	*p = *q;
	*q = tmp;
}

void main(void)
{
	int a = 10, b = 20;

	printf("Before : %d %d\n", a, b);
	Swap(&a, &b);
	printf("After : %d %d\n", a, b);
}

#endif



// ----------------------------------------------------------------------------//

// E9 

// 문제 - 문자열 바꾸기

#if 0

void Swap(p, q)  // <-
{
				 // <-
}

void main(void)
{
	char* a = "hello";
	char* b = "hi";

	printf("Before : %s, %s\n", a, b);
	Swap(, );							 // <-
	printf("After : %s, %s\n", a, b);
}

#endif

// 정답

#if 0

void Swap(char** p, char** q)  // 기본 자료형 swap하기 위해서 *썼으니 포인터를 swap하기 위해서는 이중 포인터 사용
{
	char* tmp = *p; // hello 문자열의 주소 tmp에 대입
	*p = *q;		// 포인터 p에 hi주소 대입
	*q = tmp;		// 포인터 q에 tmp에 담아뒀던 hello주소 대입
}

#endif



