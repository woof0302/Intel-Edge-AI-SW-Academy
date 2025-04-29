// 인텔 ai sw 과정 자료구조 수업 중 ptr 개념 보강 (2024.11.27 ~ 2024.11.29)  

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h> 



// ----------------------------------------------------------------------------//

// F0

// 문제 - func 함수의 parameter를 완성하라
#if 0

void func(p)
{
    // main의 a[2]를 50으로 만드는 코드를 설계하라

    = 50;
}

void main(void)
{
    int a[4] = { 10,20,30,40 };

    printf("%d\n", a[2]);
    func(&a);               // 배열 주소를 매개변수로 받는다
    printf("%d\n", a[2]);
}

#endif

// 정답

#if 0

void func(int(*p)[4]) 
{
    (*p)[2] = 50;     // (*p) == { 10,20,30,40 }
}

#endif



// ----------------------------------------------------------------------------//

// F1
 
//  문제 - 구조체 주소의 함수 전달
// 함수에서 score를 100으로 수정하는 코드를 작성하라
// 단, -> 연산자는 사용할 수 없다     // 즉 . 멤버 접근 연산자를 써야 한다는 뜻
#if 0

struct math
{
    int id;
    char name[20];
    int score;
};

void cheat(struct math* test);

void main(void)
{
    struct math final = { 1, "Kim", 50 };
    cheat(&final);              // 구조체 주소를 인수로 함수를 호출했다.
    printf("%d\n", final.score);
}

void cheat(struct math* test)
{
    = 100;          // <-
}

#endif

// 정답

#if 0

void cheat(struct math* test)
{
    (*test).score = 100;  // test는 구조체 포인터니 * 연산자로 구조체에 접근 후 . 연산자로 멤버에 접근하면 된다.
}

#endif



// ----------------------------------------------------------------------------//

// F2

// 문제 - 배열의 액세스
#if 0

int a[3][4] = { {1,2,3,4},{5,6,7,8},{9,10,11,12} };
int* b[3] = { a[2], a[1], a[0] };

void main(void)
{
    printf("%d\n", a[2][3]);

    //b를 이용하여 배열내의 숫자 12을 인쇄하시오

    printf("%d\n", );
}


#endif

// 정답   printf("%d\n", b[0][3]);



// ----------------------------------------------------------------------------//

// F3

// 문제 - 함수 등가포인터의 실행
#if 0

int add(int a, int b)
{
    return a + b;
}

void f1(void)
{
    printf("func\n");
}

int* f2(void)
{
    static int a[4] = { 1,2,3,4 };

    return a;
}

void main(void)
{
    // p, q, r 선언

    // p, q, r에 대응 함수 대입

    printf("%d\n", add(3, 4));
    f1();
    printf("%d\n", f2()[2]);

    // 위와 동일한 결과가 나오도록 p, q, r로 실행
}

#endif

// 정답

#if 0

void main(void)
{
    // 함수 포인터 p, q, r 선언
    int(*p)(int a, int b);
    void(*q)(void);
    int* (*r)(void);

    // p, q, r에 대응 함수 대입
    p = add;
    q = f1;
    r = f2;

    printf("%d\n", add(3, 4));
    f1();
    printf("%d\n", f2()[2]);

    // 위와 동일한 결과가 나오도록 p, q, r로 실행
    printf("%d\n", p(3, 4));
    q();
    printf("%d\n", r()[2]);
    }

#endif



// ----------------------------------------------------------------------------//

// F4

// 문제 - 함수를 함수에 전달
#if 0

int add(int a, int b)
{
    return a + b;
}

int sub(int a, int b)
{
    return a - b;
}

void func()     // <-
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

void func(int(*p)(int a, int b))

#endif


