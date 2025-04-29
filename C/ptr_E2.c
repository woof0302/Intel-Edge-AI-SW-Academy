// ���� ai sw ���� �ڷᱸ�� ���� �� ptr ���� ���� (2024.11.27 ~ 2024.11.29)  

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h> 



// ----------------------------------------------------------------------------//

// E5

// ���� - '�迭 �ּ�'�� �Լ� ���� 
// f �Լ��� �����Ͽ� a[2]�� 3�� x�� ����ǵ��� �ڵ带 �ϼ��϶�

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

// ����

#if 0

int(*f(void))[4] // �����ǵ��� �迭 �ּ�(int 4���� ���ҷ� ����)�� ��ȯ�ϴ� ��   ���� int ���� ���ҷ� ���� �迭�� �����Ͱ� ��ȯ Ÿ���� �ȴ�.
{
	static int a[4] = { 1,2,3,4 }; // static���� �迭 ������ ���α׷� ��ü�� Ȯ��

	return &a;  // �迭�� �ּ� ��ȯ  &�����ڴ� �迭�� ������ �迭 ��ü�μ� �ٷ������ �� ��� �� �ϳ�
}

void main(void)
{
	int x;

	x = f()[0][2];  // a�� (int ���� ���ҷ� ���� �迭) �������̱� ������ f()[0] �� �迭 a�� ù ������ �ּҰ� �ȴ�.
					// �׸��� �� Ÿ���� int * Ÿ���� �������̹Ƿ�, �迭ó�� �ε����� �� �ְԵȴ�.
	printf("%d\n", x);
}


#endif



// ----------------------------------------------------------------------------//

// E6

// ���� - �迭 �ּ��� �Լ� ����
// f �Լ��� �����Ͽ� a[2]�� 3�� x�� ����ǵ��� �ڵ带 �ϼ��϶�
#if 0

#include <stdio.h> 

f(void)   // <- ��ȯ�� �ϼ�
{
    static int a[4] = { 1,2,3,4 };

    return &a - 1;		// int �ϳ��� �ƴ϶�   int �迭[4] ��ŭ ������ ������
}

void main(void)
{
    int x;

    x =  //  <-

        printf("%d\n", x);
}

#endif

// ����

x = f()[1][2];	// ù ��° �ε����� �迭a�� ���� �� ��° �ε����� ����° ���� ����







// ----------------------------------------------------------------------------//

// E7

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

// ����

#if 0

void func(int(*p)(int, int)) // �������ε� int �ΰ��� �Ű������� ���� int�� ��ȯ�ϴ� �Լ� ������

#endif



// ----------------------------------------------------------------------------//

// E8 

// ���� - ���� ������
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

// ����

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

// ���� - ���ڿ� �ٲٱ�

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

// ����

#if 0

void Swap(char** p, char** q)  // �⺻ �ڷ��� swap�ϱ� ���ؼ� *������ �����͸� swap�ϱ� ���ؼ��� ���� ������ ���
{
	char* tmp = *p; // hello ���ڿ��� �ּ� tmp�� ����
	*p = *q;		// ������ p�� hi�ּ� ����
	*q = tmp;		// ������ q�� tmp�� ��Ƶ״� hello�ּ� ����
}

#endif



