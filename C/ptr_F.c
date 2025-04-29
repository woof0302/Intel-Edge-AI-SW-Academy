// ���� ai sw ���� �ڷᱸ�� ���� �� ptr ���� ���� (2024.11.27 ~ 2024.11.29)  

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h> 



// ----------------------------------------------------------------------------//

// F0

// ���� - func �Լ��� parameter�� �ϼ��϶�
#if 0

void func(p)
{
    // main�� a[2]�� 50���� ����� �ڵ带 �����϶�

    = 50;
}

void main(void)
{
    int a[4] = { 10,20,30,40 };

    printf("%d\n", a[2]);
    func(&a);               // �迭 �ּҸ� �Ű������� �޴´�
    printf("%d\n", a[2]);
}

#endif

// ����

#if 0

void func(int(*p)[4]) 
{
    (*p)[2] = 50;     // (*p) == { 10,20,30,40 }
}

#endif



// ----------------------------------------------------------------------------//

// F1
 
//  ���� - ����ü �ּ��� �Լ� ����
// �Լ����� score�� 100���� �����ϴ� �ڵ带 �ۼ��϶�
// ��, -> �����ڴ� ����� �� ����     // �� . ��� ���� �����ڸ� ��� �Ѵٴ� ��
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
    cheat(&final);              // ����ü �ּҸ� �μ��� �Լ��� ȣ���ߴ�.
    printf("%d\n", final.score);
}

void cheat(struct math* test)
{
    = 100;          // <-
}

#endif

// ����

#if 0

void cheat(struct math* test)
{
    (*test).score = 100;  // test�� ����ü �����ʹ� * �����ڷ� ����ü�� ���� �� . �����ڷ� ����� �����ϸ� �ȴ�.
}

#endif



// ----------------------------------------------------------------------------//

// F2

// ���� - �迭�� �׼���
#if 0

int a[3][4] = { {1,2,3,4},{5,6,7,8},{9,10,11,12} };
int* b[3] = { a[2], a[1], a[0] };

void main(void)
{
    printf("%d\n", a[2][3]);

    //b�� �̿��Ͽ� �迭���� ���� 12�� �μ��Ͻÿ�

    printf("%d\n", );
}


#endif

// ����   printf("%d\n", b[0][3]);



// ----------------------------------------------------------------------------//

// F3

// ���� - �Լ� ��������� ����
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
    // p, q, r ����

    // p, q, r�� ���� �Լ� ����

    printf("%d\n", add(3, 4));
    f1();
    printf("%d\n", f2()[2]);

    // ���� ������ ����� �������� p, q, r�� ����
}

#endif

// ����

#if 0

void main(void)
{
    // �Լ� ������ p, q, r ����
    int(*p)(int a, int b);
    void(*q)(void);
    int* (*r)(void);

    // p, q, r�� ���� �Լ� ����
    p = add;
    q = f1;
    r = f2;

    printf("%d\n", add(3, 4));
    f1();
    printf("%d\n", f2()[2]);

    // ���� ������ ����� �������� p, q, r�� ����
    printf("%d\n", p(3, 4));
    q();
    printf("%d\n", r()[2]);
    }

#endif



// ----------------------------------------------------------------------------//

// F4

// ���� - �Լ��� �Լ��� ����
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

// ����

#if 0

void func(int(*p)(int a, int b))

#endif


