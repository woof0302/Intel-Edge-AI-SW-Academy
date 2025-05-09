// 인텔 ai sw 과정 C++ OOP 수업  류경식 교수님 강의 (2024.12.24 ~ 2025.1.3) 수업 실습자료와 수업 들으면서 작성한 주석



// C++ 표준 console 출력

#if 0

#include <iostream>

int main(void)  // c표준은 parameter 없을 때 void 
{
	for (int i = 0; i < 10; i++) // for문 내에서 변수 선언하는 것은 C99 문법 / C91에서는 변수 선언을 전역으로 또는 함수 초반에 해야하기 때문에 error 
	{
		// std::cout << "i * i = " << i * i << " 입니다\n";
		// std::cout << "i * i = " << i * i << " 입니다" << std::endl; 

		std::cout << i << " * " << i << " = " << i * i << std::endl;   // \n 이 프로그램 실행 속도가 더 빠름 (함수임)   모니터에 반영되는건 더 느리지만
																	   // endl 출력버퍼를 모니터에 반영(모니터에 반영되는건 더 빠름) 
																	   // printf < std::cout  실행속도

	}

	return 0;
}

#endif

// Namespace와 :: 연산자   (scope resoulution 연산자)

#if 0

#include <iostream>

int x, y;

namespace my
{
	int x, y;

	int func(int a, int b)
	{
		return a + b;
	}
}

namespace your
{
	int x, y;

	int func(int a, int b)
	{
		return a - b;
	}
}

int main()
{
	my::x = 10, my::y = 20;
	std::cout << my::func(my::x, my::y) << std::endl;

	x = 5, y = 10;
	your::x = 100, your::y = 200;
	std::cout << your::func(x, y) << std::endl;

	return 0;
}

#endif

// using 'directive'를 이용한 namespace 사전 지정

#if 0

#include <iostream>

int x, y;

namespace my
{
	int x, y;

	int func(int a, int b)
	{
		return a + b;
	}
}

namespace your
{
	int x, y;

	int func(int a, int b)
	{
		return a - b;
	}
}

int main()
{
	using namespace my;

	x = 10, y = 20;  // 73 번 줄과 77번 줄 충돌
	your::x = 100, your::y = 200;
	std::cout << func(x, y) << std::endl;

	return 0;
}

#endif

// using 'declarataion'을 이용한 namespace 사전 지정

#if 0

#include <iostream>

int x, y; // 전역변수가 있더라도 

namespace my
{
	int x, y;

	int func(int a, int b)
	{
		return a + b;
	}
}

namespace your
{
	int x, y;

	int func(int a, int b)
	{
		return a - b;
	}
}

int main()
{
	using my::x;	//declaration 을 이용한 지정을 했기 때문에 
	using my::y;

	my::x = 10, y = 20;		//my의 x, y가 사용된다
	std::cout << my::func(x, y) << std::endl;

	return 0;
}

#endif

// std를 생략하기 위한 using의 사용 p.17

#if 0

#include <iostream>
#include <cstdio>

using namespace std;

int main()
{
	std::cout << "Hello 1\n";
	cout << "Hello 2" << endl; // 156줄로 인해 std:: 생략이 가능
	printf("hello 3\n");
	std::printf("hello 4\n");

	return 0;
}

#endif

// in/out manipulator p.18

#if 0

#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
	int a = 100;

	cout << hex << a << " " << dec << a << " " << oct << a << endl;		// cout 에 함수 hex() 넣고 a 넣어준걸로 해석
	cout << showbase << uppercase << hex << a << " " << dec << a << " " << oct << a << endl;  // showbase() 진법에 맞춰 출력해주는 함수 
	cout << a << endl;		// 토글 형식이어서 마지막에 지정한 oct 형식으로 출력된다  // 진법 표시 안하려면  noshowbase로 해제해야한다.  -> https://en.cppreference.com/w/cpp/io/manip
	cout << setw(8) << dec << a << endl;
	cout << setw(8) << -100 << " " << setfill('*') << left << setw(8) << dec << a << endl;
	cout << a << endl;

	return 0;
}

#endif


// C++ 표준 console 입력 p.19

#if 0

#include <iostream>
using namespace std;

int main()
{
	int x;

	cout << "정수 값 입력 ";
	cin >> x;
	cout << "입력은 " << x << " 입니다" << endl;

	cout << "16진수 값 입력 ";
	cin >> hex >> x;
	cout << "입력은 " << x << " 입니다" << endl;

	return 0;
}

#endif

// C++ 표준 console 입력 : 여러 정수 값 받기 p.19

#if 0

#include <iostream>
using namespace std;

int main()
{
	int x, y, z;

	cout << "정수 3개 입력 ";
	cin >> x >> y >> z;			//cin - stream buffer에서 값을 추출해온다
	cout << " x = " << x << " y = " << y << " z = " << z << endl;

	return 0;
}

#endif


// C++ 표준 console 입력 : 문자열 입력 받기(공백 포함 받기)

#if 0

#include <iostream>
using namespace std;

int main()
{
	double d;
	char s[20];

	cout << "실수 값 입력 ";
	cin >> d;
	cout << d << endl;

	cout << "두 단어 입력(Hello World)" << endl;
	cin >> s;
	cout << s << endl;		// Hello만 나옴		white space (공백 줄바꿈 백스페이스 tab) 있는 곳 까지만 데려옴

	return 0;
}

#endif

// C++ 표준 console 입력 : cin.getline으로 문자열 입력 받기 p.20

#if 0

#include <iostream>			// 에러 - 실수 값 입력 후 남아 있는 줄바꿈 때문에 -> getline을 한 번 더 쓰면 해결 가능(다음 예제)
using namespace std;

int main()
{
	double d;
	char s[20];

	cout << "실수 값 입력 ";
	cin >> d;
	cout << d << endl;

	cout << "두 단어 입력(Hello World)" << endl;
	cin.getline(s, 20);		// . 구조체 멤버 접근 연산자 stream buffer에서 white space 무시하고 줄바꿈 있을 때까지 가져온다
	cout << s << endl;

	return 0;
}

#endif

// C++ 표준 console 입력 : cin.ignore() 

#if 0

#include <iostream>
using namespace std;

int main()
{
	double d;
	char s[20];

	cout << "실수 값 입력 ";		//  \n 언제 모니터에 출력될지 모름    endl 바로 모니터로 출력
	cin >> d;
	cout << d << endl;

	cin.ignore();		// 한 글자 날리기
	//cin.getline(s, 20);

	cout << "두 단어 입력(Hello World)" << endl;
	cin.getline(s, 20);
	cout << s << endl;

	return 0;
}

#endif

// 상수 표현, 변수 초기화

#if 0

#include <iostream>
using namespace std;

struct st
{
	int a = -10;
	char b;
};

int main()
{
	int a = 0b1010;
	int b(20);
	int c{ 30 };

	cout << a << endl;
	cout << b << endl;
	cout << c << endl;

	int d[2] = { 40,50 };
	int e[2]{ 60,70 };

	struct st f = { 80, 'A' };
	st g{ 90, 'B' };

	cout << d[1] << endl;
	cout << e[1] << endl;
	cout << f.a << endl;
	cout << g.b << endl;
}

#endif

// 함수의 Default Parameter p.22

#if 0

#include <iostream>
using namespace std;

int f1(int a, int b = 10, int c = 20)
{
	return a + b + c;
}

int f2(int x, int y = 10, int z = 20);

int main()
{
	cout << f1(10, 100, 200) << endl;
	cout << f1(10, 100) << endl;
	cout << f1(10) << endl;

	cout << f2(10, 100, 200) << endl;
	cout << f2(10, 100) << endl;
	cout << f2(10) << endl;

	return 0;
}

int f2(int xx, int yy, int zz)
{
	return xx + yy + zz;
}

#endif

// 함수 Overloading p.23

#if 0

#include <iostream>
using namespace std;

int f(int a)
{
	return a * a;
}

int f(int x, int y)
{
	return x * y;
}

void f(double x)
{
	cout << x << endl;
}

double f(double x, double y)
{
	return x + y;
}

int main()
{
	cout << f(10) << endl;
	cout << f(10, 20) << endl;
	f(3.14);
	cout << f(3.14, 5.5) << endl;
	cout << f(3, 5.5) << endl;

	return 0;
}

#endif

// Parameter 타입의 Template 지정

#if 0

#include <iostream>
using namespace std;

template<typename T>
T f1(T x, T y)
{
	return x + y;
}

template<typename myT>
myT f2(myT x, int y)
{
	return x + y;
}

template<typename myT>
int f3(myT x, int y)
{
	return x + y;
}

int main()
{
	cout << f1(10, 20) << endl;
	cout << f1(3.14, 5.5) << endl;

	cout << f2<int>(10, 20) << endl;
	cout << f2<double>(3.14, 30) << endl;

	cout << f3<int>(10, 20) << endl;
	cout << f3<double>(3.14, 30) << endl;

	return 0;
}

#endif

// 동적 메모리 할당(new, delete)

#if 0

#include <iostream>
using namespace std;

struct _st
{
	int a;
	char b;
};

int main()
{
	int * p = new int;
	char * q = new char[4];
	int(*r)[4] = new int[3][4];
	_st * x = new _st[2];

	p[0] = 10;
	q[3] = 'A';
	r[2][3] = 100;
	x[1].b = 'B';

	cout << p[0] << endl;
	cout << q[3] << endl;
	cout << r[2][3] << endl;
	cout << x[1].b << endl;

	delete p;
	delete[] q;
	delete[] r;
	delete[] x;

	return 0;
}

#endif

// inline 함수

#if 0

#include <iostream>
using namespace std;

inline int f(int x)
{
	return x * x;
}

int main()
{
	cout << f(3) << endl;

	return 0;
}

#endif

// refernce &의 의미

#if 0

#include <iostream>
using namespace std;

int main()
{
	int a = 10;
	int &b = a;
	int *p = &a;

	b = 20;
	cout << a << " " << b << endl;
	*p = 30;
	cout << a << " " << *p << endl;

	return 0;
}

#endif

// Call by reference와 & Modifier

#if 0

#include <iostream>
using namespace std;

void f1(int x)
{
	x = 10;
}

void f2(int *p)
{
	p[1] = 20;
}

void f3(int &r)
{
	r = 30;
}

void f4(const int &s)
{
	cout << s << endl;
}

int main()
{
	int a[4] = { 1,2,3,4 };

	f1(a[0]);
	f2(a);
	f3(a[2]);

	cout << a[0] << endl;
	cout << a[1] << endl;
	cout << a[2] << endl;

	f4(a[3]);

	return 0;
}

#endif

// ranged for

#if 0

#include <iostream>
using namespace std;

int main()
{
	int a[4] = { 1,2,3,4 };

	for (int i = 0; i < sizeof(a) / sizeof(a[0]); i++)
	{
		cout << a[i] << endl;
	}

	for (int x : a)
	{
		cout << x << endl;
	}

	return 0;
}

#endif

// auto 타입, bool 타입

#if 0

#include <iostream>
using namespace std;

char func()
{
	return 'X';
}

int main()
{
	auto a = 100;
	auto b = 3.14;
	bool c = false;
	bool d = ((10 < 20) == true);
	auto e = func();
	int f[] = { 1,3,5, };

	cout << e << endl;
	cout << c << ":" << d << endl;

	for (const auto &x : f)
	{
		cout << x << endl;
	}

	return 0;
}

#endif

// Procedural 방식

#if 0

#include <iostream>
using namespace std;

int total = 0;

void mart_calc(int price)
{
	total += price;
}

int main(void)
{
	mart_calc(10);
	cout << "total=" << total << endl;

	mart_calc(20);
	cout << "total=" << total << endl;

	return 0;
}

#endif

// Procedural의 공동 사용시 고려할 점

#if 0

#include <iostream>
using namespace std;

int total[4] = { 0,0,0,0 };

void mart_calc(int user, int price)
{
	total[user] += price;
}

int main(void)
{
	mart_calc(0, 10);
	mart_calc(0, 20);
	cout << "total[0]=" << total[0] << endl;

	mart_calc(1, 200);
	cout << "total[1]=" << total[1] << endl;

	mart_calc(0, 50);
	cout << "total[0]=" << total[0] << endl;

	return 0;
}

#endif

// 구조체를 이용한 Object 생성

#if 0

#include <iostream>
using namespace std;

struct _st
{
private:
	double irate = 0.02;

	void disp_total(void)
	{
		cout << total << endl;
	}

public:
	double total = 0;

	double func(int x)
	{
		total += x * (1 + irate);
		disp_total();
		return total;
	}
};

int main()
{
	_st y;

	cout << y.func(50) << endl;
	cout << y.func(100) << endl;

	return 0;
}

#endif

// 기본 Class, Object(Instance) 생성 및 사용

#if 0

#include <iostream>
using namespace std;

class mart_calc
{
public:
	int total = 0;

	void buy(int price)
	{
		total += price;
	}
};

int main(void)
{
	mart_calc calc1;
	mart_calc calc2;

	calc1.buy(10);
	calc1.buy(20);
	cout << calc1.total << endl;

	calc2.buy(200);
	cout << calc2.total << endl;

	calc1.buy(50);
	cout << calc1.total << endl;

	return 0;
}

#endif

// Member Function을 외부에 정의

#if 0

#include <iostream>
using namespace std;

class mart_calc
{
private:
	double tax = 0.01;
	void disp_total(void);

public:
	double total = 0;
	void buy(int price);
};

void mart_calc::disp_total(void)
{
	cout << "total=" << total << endl;
}

void mart_calc::buy(int price)
{
	total += price * (1 + tax);
	disp_total();
}

int main(void)
{
	mart_calc calc1;
	mart_calc calc2;

	calc1.buy(10);
	calc1.buy(20);
	cout << calc1.total << endl;

	calc2.buy(200);
	cout << calc2.total << endl;

	calc1.buy(50);
	cout << calc1.total << endl;

	return 0;
}

#endif

// change_tax method 구현(parameter 이름과 private 이름 중복)

#if 0

#include <iostream>
using namespace std;

class mart_calc
{
private:
	double tax = 0.01;

public:
	double total = 0;
	void buy(int price);
	void change_tax(double tax);
};

void mart_calc::buy(int price)
{
	total += price * (1 + tax);
}

void mart_calc::change_tax(double tax)
{
	// class의 private 변수 tax를 전달 받은 값으로 변경

}

int main(void)
{
	mart_calc calc1;
	mart_calc calc2;

	calc1.change_tax(0.02);

	calc1.buy(10);
	calc1.buy(20);
	cout << calc1.total << endl;

	calc2.buy(200);
	cout << calc2.total << endl;

	calc1.buy(50);
	cout << calc1.total << endl;

	return 0;
}

#endif

// buy method overloding

#if 0

#include <iostream>
using namespace std;

class mart_calc
{
private:
	double tax = 0.01;

public:
	double total = 0;
	void buy(int price);
	void buy(int price, double tax);
};

void mart_calc::buy(int price)
{
	total += price * (1 + tax);
}

void mart_calc::buy(int price, double tax)
{
	total += price * (1 + tax);
}

int main(void)
{
	mart_calc calc1;
	mart_calc calc2;

	calc1.buy(10);
	calc1.buy(20, 0.1);
	cout << calc1.total << endl;

	calc2.buy(200, 0.1);
	cout << calc2.total << endl;

	calc1.buy(50);
	cout << calc1.total << endl;

	return 0;
}

#endif

// default를 사용한 buy method

#if 0

#include <iostream>
using namespace std;

class mart_calc
{
public:
	double total = 0;
	void buy(int price, double tax = 0.01);
};

// member function buy 설계

int main(void)
{
	mart_calc calc1;
	mart_calc calc2;

	calc1.buy(10);
	calc1.buy(20, 0.1);
	cout << calc1.total << endl;

	calc2.buy(200, 0.1);
	cout << calc2.total << endl;

	calc1.buy(50);
	cout << calc1.total << endl;

	return 0;
}

#endif

// 생성자에 의한 초기화

#if 0

#include <iostream>
using namespace std;

int rent_count = 0;

class mart_calc
{
public:
	double total = 0;

	mart_calc(int price)
	{
		rent_count++;
		total += price;
	}

	void buy(int price);
};

void mart_calc::buy(int price)
{
	total += price;
}

int main(void)
{
	mart_calc calc1(10);	// calc1 total 10
	mart_calc calc2(100);	// calc2 total 100

	cout << "CNT=" << rent_count << endl;

	calc1.buy(10);	// calc1 total 20
	calc1.buy(20);	// calc1 total 40
	cout << calc1.total << endl;

	calc2.buy(200);	// calc2 total 300
	cout << calc2.total << endl;

	return 0;
}

#endif

// Constructor 실행 및 Overloading

#if 0

#include <iostream>
using namespace std;

class buf
{
public:
	int * p;

	buf()
	{
		p = new int[4];
	}

	buf(int size)
	{
		p = new int[size];
	}

	void wr_buf(int i, int v)
	{
		p[i] = v;
	}
};

int main(void)
{
	buf x;
	buf y(); // 얘 에러 - 생성자로 쓰려는 의도와 다르게 반환 타입이 buf이고 매개변수 받지 않는 함수 선언으로 해석됨
	buf z(10);

	x.wr_buf(3, 100);
	z.wr_buf(9, 200);

	cout << x.p[3] << " " << z.p[9] << endl;

	return 0;
}

#endif

// 모든 parameter가 default인 constructor

#if 0

#include <iostream>
using namespace std;

class buf
{
public:
	int * p;

	buf(int size = 4)
	{
		cout << "H" << endl;
		p = new int[size];
	}

	void wr_buf(int i, int v)
	{
		p[i] = v;
	}
};

int main(void)
{
	buf x(); //    <- 에러 원인 디폴트 생성자 호출은 빈 괄호 () 없이 해야함
	buf y;
	buf z(10);

	x.wr_buf(3, 100);
	y.wr_buf(3, 100);
	z.wr_buf(9, 200);

	cout << x.p[3] << endl;
	cout << y.p[3] << endl;
	cout << z.p[9] << endl;

	return 0;
}

#endif

// 소멸자 의한 객체 삭제

#if 0

#include <iostream>
using namespace std;

int rent_count = 0;

class mart_calc
{
public:
	double total = 0;

	mart_calc(int price)	// 생성자
	{
		rent_count++;
		total += price;
	}

	~mart_calc()  // 소멸자
	{
		rent_count--;
	}

	void buy(int price)
	{
		total += price;
	}
};

// 만약 이렇게 calc0를 전역에서 선언 했다면? 어떻게 될까?
// mart_calc calc0(10);

int main(void)
{
	{
		mart_calc calc1(10);
		{
			mart_calc calc2(100);

			cout << "CNT=" << rent_count << endl;

			calc1.buy(10);
			calc1.buy(20);
			cout << calc1.total << endl;

			calc2.buy(200);
			cout << calc2.total << endl;
		}
		cout << "CNT=" << rent_count << endl;
	}

	cout << "CNT=" << rent_count << endl;

	return 0;
}

#endif

// 배열, 포인터로 instance 생성

#if 0

#include <iostream>
using namespace std;

class buf
{
public:
	int p[4];

	void wr_buf(int i, int v)
	{
		p[i] = v;
	}
};

int main(void)
{
	buf x;
	buf y[2];
	buf *z = new buf;

	x.wr_buf(3, 100);
	y[1].wr_buf(3, 200);
	z->wr_buf(2, 300);
	(*z).wr_buf(3, 400);

	cout << x.p[3] << endl;
	cout << y[1].p[3] << endl;
	cout << z->p[2] << endl;
	cout << (*z).p[3] << endl;

	delete z;

	return 0;
}

#endif

// 정적 멤버 => static member data

#if 0

#include <iostream>
using namespace std;

class mart_calc
{
public:
	static int rent_count;
	static int sales_total;
	double total = 0;

	mart_calc(int price)
	{
		rent_count++;
		total += price;
		sales_total += price;
	}

	void buy(int price)
	{
		total += price;
		sales_total += price;
	}
};

int mart_calc::rent_count = 0;
int mart_calc::sales_total = 0;

int main(void)
{
	mart_calc calc1(10);
	mart_calc calc2(100);

	cout << "CNT=" << mart_calc::rent_count << endl;
	cout << "CNT=" << calc1.rent_count << endl;

	calc1.buy(10);
	calc1.buy(20);
	cout << calc1.total << endl;

	calc2.buy(200);
	cout << calc2.total << endl;

	cout << "CNT=" << mart_calc::sales_total << endl;

	return 0;
}

#endif

// 정적 멤버 => static member function

#if 0

#include <iostream>
using namespace std;

void prt(void)
{
	cout << "Static Function" << endl;
}

class mart_calc
{
public:
	double total = 0;
	static int rent_count;

	mart_calc(int price)
	{
		rent_count++;
		total += price;
	}

	void buy(int price)
	{
		total += price;
	}

	static double get_total(void)
	{
		prt();
		return rent_count;
	}
};

int mart_calc::rent_count = 0;

int main(void)
{
	mart_calc calc1(10);
	mart_calc calc2(100);

	cout << calc1.total << endl;
	cout << calc2.total << endl;

	cout << "CNT=" << mart_calc::get_total() << endl;
	cout << "CNT=" << calc1.get_total() << endl;

	return 0;
}

#endif

// Instance 생성의 실체

#if 0

#include <iostream>
using namespace std;

class A
{
public:
	int x, y;

	A(int xx = 3, int yx = 10) : x(xx + 1), y(yx + 2)
	{
		cout << "xx=" << xx << " A::x=" << A::x << endl;
	}
};

int main(void)
{
	int a;

	int a0;
	int a1 = 10;
	int a2(10);
	int a3 = { 10 };
	int a4{ 10 };	// 다 가능

	A d;
	A e1(500);
	A e2(500);
	A e3 = (500, 600);
	A e4{ 500, 600 };       //int 로 선언하나 class로 선언하나 모두 같은 form으로 가능하다

	int b = 100;
	int c(200);

	A d;
	A e(500);
	A f = A(1000);

	cout << b << endl;
	cout << c << endl;
	cout << d.x << endl;
	cout << e.x << endl;
	cout << f.x << endl;

	return 0;
}

#endif

// Constructor를 초기화 List로 사용하는 경우

#if 0

#include <iostream>
using namespace std;

class student
{
public:
	const int age;
	const char * name;

	student(int a, const char * n)
	{
		age = a;
		name = n;
	}
};

int main(void)
{
	student x(10, "KIM");

	cout << x.age << endl;
	cout << x.name << endl;

	return 0;
}

#endif

// 상수 멤버 함수(Const Member Function)

#if 0

#include <iostream>
using namespace std;

class student
{
public:
	int age;

	student(int a) : age(a) {}

	int func(int inc) const
	{
		int r;

		inc++;
		r = age + inc;

		age = r;

		cout << age << " " << r << endl;
		return inc;
	}
};

int main(void)
{
	student x(10);

	cout << x.func(2) << endl;

	return 0;
}

#endif

// 상수 멤버 함수(Const Member Function)

#if 0

#include <iostream>
using namespace std;

class student
{
public:
	int age;

	student(int a) : age(a) {}

	int func(int inc) const
	{
		int r;

		inc++;
		r = age + inc;

		age = r;

		cout << age << " " << r << endl;
		return inc;
	}
};

int main(void)
{
	student x(10);

	cout << x.func(2) << endl;

	return 0;
}

#endif

// const instnace의 제약 사항

#if 0

#include <iostream>
using namespace std;

class student
{
public:
	int age;

	student(int a) : age(a) {}

	int func()
	{
		cout << age << endl;
		return age;
	}
};

int main(void)
{
	const student x(10);

	x.age = 20;					// const여서 멤버 데이터를 바꾸려하면 에러   // 초기화는 상관없다
	int r = x.func();			// fun()는 멤버 데이터를 바꾸지 않는데도 에러    why?  아래에서 해결법 제시 

	cout << r << endl;

	return 0;
}

#endif

// 상수 멤버 함수(Const Member Function)의 필요성

#if 0

#include <iostream>
using namespace std;

class student
{
public:
	int age;

	student(int a) : age(a) {}

	int func() const		// read only 인 함수에 const 붙여서 read only화해서 사용할 수 있다.
	{
		cout << age << endl;
		return age;
	}
};

int main(void)
{
	const student x(10);

	int r = x.func();

	cout << r << endl;

	return 0;
}

#endif

// Class에서 Type Template 사용

#if 0

#include <iostream>
using namespace std;

template <typename T> class mart_calc
{
public:
	double total = 0;

	mart_calc(T price)
	{
		total += price;
	}

	void buy(T price)
	{
		total += price;
	}
};

int main(void)
{
	mart_calc<int> a(10);
	mart_calc<double> b(3.5);

	a.buy(20.5);
	b.buy(10);

	cout << a.total << endl;
	cout << b.total << endl;

	return 0;
}

#endif

// Class 상속의 기본

#if 0

#include <iostream>
using namespace std;

class car
{
public:
	const char * model;
	const char * mission;
	int price;

	void set_car(const char * x, const char * y, int z)
	{
		model = x;
		mission = y;
		price = z;
	}
};

class truck : public car
{
public:
	double load;

	void set_info(double v)
	{
		load = v;
	}
};

class van : public car
{
public:
	int passenger;

	void set_info(int v)
	{
		passenger = v;
	}
};

int main(void)
{
	car a;
	truck b;
	van c;

	a.set_car("Sonata", "Auto", 1200);
	b.set_car("Bongo", "Manual", 900);
	b.set_info(2.5);
	c.set_car("Carnival", "Auto", 2400);
	c.set_info(11);

	cout << a.model << endl;
	cout << b.model << endl;
	cout << b.load << endl;
	cout << c.model << endl;
	cout << c.passenger << endl;

	return 0;
}

#endif

// 상속의 대상과 Access Modifier

#if 0

#include <iostream>
using namespace std;

class A
{
public:
	int a = 10;
protected:
	int b = 20;
private:
	int c = 30;
};

class B : public A
{
public:
	int d = 40;

	void f(void)
	{
		cout << a << endl;
		cout << b << endl;
		// cout << c << endl;
		cout << d << endl;
	}
};

int main(void)
{
	A aa;
	B bb;

	cout << aa.a << endl;
	cout << aa.b << endl;
	// cout << aa.c << endl;

	cout << bb.a << endl;
	cout << bb.b << endl;
	// cout << bb.c << endl;
	cout << bb.d << endl;

	bb.f();

	return 0;
}

#endif

// 상속 받을때 상속 받는 멤버의 접근성 변경

#if 0

#include <iostream>
using namespace std;

class A
{
public:
	int a = 10;
protected:
	int b = 20;
private:
	int c = 30;	// c 는 private이여서 애초에 상속 대상이 아님
};

class B : public A
{
public:
	void f()
	{
		cout << a << endl;
		cout << b << endl;
		// cout << c << endl;
	}
};

class C : protected A
{
public:
	void f()
	{
		cout << a << endl;
		cout << b << endl;
		// cout << c << endl;
	}
};

class D : private A
{
public:
	void f()
	{
		cout << a << endl;
		cout << b << endl;
		// cout << c << endl;
	}
};

int main()
{
	B x;
	cout << x.a << endl;
	cout << x.b << endl;
	// cout << x.c << endl;
	x.f();

	C y;
	cout << y.a << endl;
	cout << y.b << endl;
	// cout << y.c << endl;
	y.f();

	D z;
	cout << z.a << endl;
	cout << z.b << endl;
	// cout << z.c << endl;
	z.f();

	return 0;
}

#endif

// friend class, friend function 지정

#if 0

#include <iostream>
using namespace std;

class A
{
private:
	int a;

protected:

	void f()
	{
		cout << a << endl;
	}

	friend class B;
	friend void h();
};

class B
{
public:

	void g()
	{
		A x;
		x.a = 40;
		x.f();
	}
};

void h()
{
	A x;
	x.a = 50;
	x.f();
}

int main()
{
	B y;
	y.g();
	h();

	return 0;
}

#endif

// 상속 Class의 constructor, destructor 동작 순서

#if 0

#include <iostream>
using namespace std;

class A
{
public:
	A()
	{
		cout << "A" << endl;
	}
	~A()
	{
		cout << "~A" << endl;
	}
};

class B : public A
{
public:
	B()  // B() : A() => 이렇게 설계해도 무방(기본적으로 해 줌)
	{
		cout << "B" << endl;
	}
	~B()
	{
		cout << "~B" << endl;
	}
};

int main()
{
	B x;

	return 0;
}

#endif

// Base Class가 default constructor일 경우

#if 0

#include <iostream>
using namespace std;

class A
{
public:
	A()
	{
		cout << "A" << endl;
	}
};

class B : public A
{
public:
	B(int x)
	{
		cout << "B:" << x << endl;
	}
};

int main()
{

	B b(3);

	return 0;
}

#endif

// Base Class가 default constructor가 아닐 경우

#if 0

#include <iostream>
using namespace std;

class A
{
public:
	A(int n)
	{
		cout << "A" << n << endl;
	}
};

class B : public A
{
public:
	B(int x) : A(x + 1)
	{
		cout << "B:" << x << endl;
	}
};

int main()
{
	B x(3);
	B y(10);

	return 0;
}

#endif

// Derived Class에서 Base Constructor 사용 예

#if 0

#include <iostream>
using namespace std;

class car
{
public:
	const char * model;
	int price;

	car(const char * x, int z)
	{
		model = x;
		price = z;
	}
};

class truck : public car
{
public:
	double load;

	truck(const char * x, int z, int v) : car(x, z)
	{
		load = v;
	}
};

class van : public car
{
public:
	int passenger;

	van(const char * x, int z, int v) : car(x, z)
	{
		passenger = v;
	}
};

int main(void)
{
	car a("Sonata", 1200);
	truck b("Bongo", 900, 2.5);
	van c("Carnival", 2400, 11);

	cout << a.model << endl;
	cout << b.model << endl;
	cout << b.load << endl;
	cout << c.model << endl;
	cout << c.passenger << endl;

	return 0;
}

#endif

// Class 포인터를 전달 받는 함수의 문제점

#if 0

#include <iostream>
using namespace std;

class car
{
public:
	const char * model;
	const char * mission;
	int price;
};

class truck : public car
{
public:
	double load;
};

class van : public car
{
public:
	int passenger;
};

void prt_price(truck *p)
{
	cout << p->price << endl;
}

int main(void)
{
	truck x;
	van y;

	x.price = 1200;
	y.price = 2400;

	prt_price(&x);
	prt_price(&y);

	return 0;
}

#endif

// derived class 포인터의 upcasting

#if 0

#include <iostream>
using namespace std;

class car
{
public:
	const char * model;
	const char * mission;
	int price;
};

class truck : public car
{
public:
	double load;
};

class van : public car
{
public:
	int passenger;
};

void prt_price(car *p)
{
	cout << p->price << endl;
}

int main(void)
{
	truck x;
	van y;

	x.price = 1200;
	y.price = 2400;

	prt_price(&x);
	prt_price(&y);

	return 0;
}

#endif

// base class 포인터의 downcasting => 에러

#if 0

#include <iostream>
using namespace std;

class car
{
public:
	const char * model;
	const char * mission;
	int price;
};

class truck : public car
{
public:
	double load;
};

int main(void)
{
	truck x;
	car * p = &x;

	x.price = 1200;
	x.load = 2.5;

	cout << p->price << endl;
	cout << p->load << endl;

	return 0;
}

#endif

// base class 포인터의 downcasting => 정상

#if 0

#include <iostream>
using namespace std;

class car
{
public:
	const char * model;
	const char * mission;
	int price;
};

class truck : public car
{
public:
	double load;
};

int main(void)
{
	truck x;
	car * p = &x;

	x.price = 1200;
	x.load = 2.5;

	cout << p->price << endl;
	cout << ((truck *)p)->load << endl;

	return 0;
}

#endif

// Multiple Inheritance 상속
// 다중 상속 Class의 constructor, destructor 동작 순서

#if 0

#include <iostream>
using namespace std;

class A
{
public:
	A()
	{
		cout << "A" << endl;
	}
	~A()
	{
		cout << "~A" << endl;
	}
};

class B
{
public:
	B()
	{
		cout << "B" << endl;
	}
	~B()
	{
		cout << "~B" << endl;
	}
};

class C : public A, public B
{
public:
	C()
	{
		cout << "C" << endl;
	}
	~C()
	{
		cout << "~C" << endl;
	}
};

int main()
{
	C x;
}

#endif

// default constructor가 아닌 경우

#if 0

#include <iostream>
using namespace std;

class A
{
public:
	A(int x)
	{
		cout << "A:" << x << endl;
	}
	~A()
	{
		cout << "~A" << endl;
	}
};

class B
{
public:
	B(int x, int y)
	{
		cout << "B:" << x + y << endl;
	}
	~B()
	{
		cout << "~B" << endl;
	}
};

class C : public A, public B
{
public:
	C() : A(3), B(10, 20)
	{
		cout << "C" << endl;
	}
	~C()
	{
		cout << "~C" << endl;
	}
};

int main()
{
	C x;
}

#endif

// 다중 상속된 class에서 Base class의 함수 사용

#if 0

#include <iostream>
using namespace std;

class A
{
public:
	void func()
	{
		cout << "A" << endl;
	}
};

class B
{
public:
	void func()
	{
		cout << "B" << endl;
	}
};

class C : public A, public B { };

int main()
{
	C x;
	x.func();
	x.A::func();
	x.B::func();

	return 0;
}

#endif

// 다중 상속된 class에서 발생할 수 있는 모호성 문제

#if 0

#include <iostream>
using namespace std;

class A
{
public:
	int a;
};

class B1 : public A
{
public:
	int b;
};

class B2 : public A
{
public:
	int b;
};

class C : public B1, public B2
{
public:
	int c;
};

int main()
{
	C x;
	x.c = 10;
	x.B1::b = 20;
	x.B2::b = 30;

	x.a = -10;

	x.B1::a = 40;
	x.B2::a = 50;

	return 0;
}

#endif

// Virtual Inheritance

#if 0

#include <iostream>
using namespace std;

class A
{
public:
	int a;
};

class B1 : virtual public A
{
public:
	int b;
};

class B2 : virtual public A
{
public:
	int b;
};

class C : public B1, public B2
{
public:
	int c;
};

int main()
{
	C x;
	x.c = 10;
	x.B1::b = 20;
	x.B2::b = 30;

	x.a = -10;

	x.B1::a = 40;
	x.B2::a = 50;

	cout << x.B1::a << endl;
	cout << x.a << endl;

	B1 y;
	y.a = 100;

	cout << y.a << endl;

	return 0;
}

#endif

// Overloading에 의한 각 instance의 멤버 함수 호출 예

#if 0

#include <iostream>
using namespace std;

class car
{
public:
	const char * model;

	void prt_car()
	{
		cout << model << endl;
	}
};

class truck : public car
{
public:
	double load;

	void prt_car()
	{
		cout << load << endl;
	}
};

void func(car * y)
{
	y->prt_car();
}

void func(truck * y)
{
	y->prt_car();
}

int main(void)
{
	car c;
	truck x;

	c.model = "Sonata";
	x.load = 2.5;

	x.prt_car();
	x.car::model = "Bongo";
	x.car::prt_car();

	func(&c);
	func(&x);

	return 0;
}

#endif

// Derived Class의 Function Override(함수 재정의)

#if 0

#include <iostream>
using namespace std;

class car
{
public:
	const char * model;
	int price;

	void prt_car()
	{
		cout << model << endl;
	}
};

class truck : public car
{
public:
	double load;

	void prt_car()
	{
		cout << load << endl;
	}
};

int main(void)
{
	car c;
	truck x;

	c.model = "Sonata";
	x.model = "Bongo";
	x.load = 2.5;

	c.prt_car(); // sonata
	x.prt_car(); // 2.5

	//연습
	x.car::prt_car(); //Bongo
	(&x)->prt_car();  // 2,5
	((car*)&x)->prt_car(); //Bongo
	return 0;
}

#endif

// Derived Class의 Function Override(함수 재정의)
// 재정의 함수가 upcasting 될 때 문제점

#if 0

#include <iostream>
using namespace std;

class car
{
public:
	const char * model;

	void prt_car()
	{
		cout << model << endl;
	}
};

class truck : public car
{
public:
	double load;

	void prt_car()
	{
		cout << load << endl;
	}
};

class van : public car
{
public:
	int passenger;

	void prt_car()
	{
		cout << passenger << endl;
	}
};

void print_info(car *p)  // car* fh 업캐스팅됨
{
	p->prt_car();
}

int main(void)
{
	truck x;
	van	y;

	x.model = "Bongo";
	x.load = 2.5;
	y.model = "Carnival";
	y.passenger = 11;

	print_info(&x);
	print_info(&y);

	return 0;
}

#endif

// Derived Class의 Function Override(함수 재정의)

#if 0

#include <iostream>
using namespace std;

class car
{
public:
	const char * model;
	int price;

	virtual void prt_car()
	{
		cout << model << endl;
	}
};

class truck : public car
{
public:
	double load;

	virtual void prt_car() override //override 써주는게 안전 
	{								// 예를 들어 prt_Car()와 같은 휴먼에러 발생을 막기위해
		cout << load << endl;
	}
};

class van : public car
{
public:
	int passenger;

	virtual void prt_car() override
	{
		cout << passenger << endl;
	}
};

void print_info(car *p)
{
	p->prt_car();
}

int main(void)
{
	car z;
	truck x;
	van	y;

	z.model = "Sonata";
	x.model = "Bongo";
	x.load = 2.5;
	y.model = "Carnival";
	y.passenger = 11;

	x.car::prt_car();	// virtual이 무시는 하지만 그 실체들은 class에 남아있다.
	y.car::prt_car();	// 그래서 직접접근으로 호출 가능

	print_info(&z);		// 일반접근 했을 때는 중복정의된 함수로 호출
	print_info(&x);
	print_info(&y);

	return 0;
}

#endif

// 기존 Class에 새로운 Derived Class C를 추가하고자 할 경우
// [1] 함수 오버로딩으로 추가

#if 0

#include <iostream>
using namespace std;

class A
{
public:
	void prt()
	{
		cout << "A" << endl;
	}
};

class B : public A
{
public:
	void prt()
	{
		cout << "B" << endl;
	}
};

class C : public A
{
public:
	void prt()
	{
		cout << "C" << endl;
	}
};

void print_info(A *p)
{
	p->prt();
}

void print_info(B *p)
{
	p->prt();
}

void print_info(C *p)
{
	p->prt();
}

int main(void)
{
	A x;
	B y;
	C z;

	print_info(&x);
	print_info(&y);
	print_info(&z);

	return 0;
}

#endif

// 기존 Class에 새로운 Derived Class C를 추가하고자 할 경우
// [2] 가상 함수 사용으로 추가 => class만 새로 구현

#if 0

#include <iostream>
using namespace std;

class A
{
public:
	virtual void prt()
	{
		cout << "A" << endl;
	}
};

class B : public A
{
public:
	virtual void prt() override
	{
		cout << "B" << endl;
	}
};

class C : public A
{
public:
	virtual void prt() override
	{
		cout << "C" << endl;
	}
};

void print_info(A *p)
{
	p->prt();
}

int main(void)
{
	A x;
	B y;
	C z;

	print_info(&x);
	print_info(&y);
	print_info(&z);

	return 0;
}

#endif

// Destructor 동작 순서에 따른 문제점

#if 0

#include <iostream>
using namespace std;

class A
{
public:
	A() { cout << "A" << endl; }
	~A() { cout << "~A" << endl; }
};

class B : public A
{
public:
	B() { cout << "B" << endl; }
	~B() { cout << "~B" << endl; }
};

void f(A * p)
{
	delete p;
}

int main()
{
	A * p = new B; // upcating

	f(p);

	return 0;		// 실행결과 A B ~A   B의 소멸자를 호출을 못해서 
}

#endif

// Virtual Destructor의 활용

#if 0

#include <iostream>
using namespace std;

class A
{
public:
	A() { cout << "A" << endl; }
	virtual ~A() { cout << "~A" << endl; }
};

class B : public A
{
public:
	B() { cout << "B" << endl; }
	~B() { cout << "~B" << endl; } // 자동으로 virtual 처리되기에 소멸자 앞에 virtual을 붙여줄 필요가 없다
};

int main()
{
	A * p = new B; // upcating

	delete p;

	return 0;
}

#endif

// Pure Virtual Function & Abstract Class

#if 0

#include <iostream>
using namespace std;

class A
{
public:
	virtual void f() = 0;
};

class B : public A
{
public:
	virtual void f() override
	{
		cout << "Hello" << endl;
	}
};

int main()
{
	A x;
	B y;

	y.f();

	return 0;
}

#endif

/// Abstract Class를 활용한 인터페이스

#if 0

#include <iostream>
using namespace std;

class items
{
public:
	virtual void move_pos() = 0;
	virtual void check_crash() = 0;
};

class enemy
{
public:
	items * obj;
	int color;
	int speed;
};

class ufo : public items
{
public:
	int posx, posy;

	virtual void move_pos() override
	{
		cout << "ufo: move" << endl;
	}

	virtual void check_crash() override
	{
		cout << "ufo: check crash" << endl;
	}
};

class missile : public items
{
public:
	int pos;
	int direction;

	virtual void move_pos() override
	{
		cout << "missile: move" << endl;
	}

	virtual void check_crash() override
	{
		cout << "missile: check crash" << endl;
	}
};

int main()
{
	enemy x;
	ufo ufo1;
	missile missile1;

	x.obj = &ufo1;
	x.speed = 2;
	x.obj->move_pos();
	x.obj->check_crash();

	x.obj = &missile1;
	x.speed = 3;
	x.obj->move_pos();
	x.obj->check_crash();

	return 0;
}

#endif

/// Object 포인터 Type은 동적으로 변경될 수 있다

#if 0

#include <iostream>
using namespace std;

class A
{
public:
	virtual void f() { cout << "A" << endl; }
};

class B : public A
{
public:
	virtual void f() override { cout << "B" << endl; }
};

class C : public B
{
public:
	virtual void f() override { cout << "C" << endl; }
};

void f(A * p)
{
	p->f();
}

int main()
{
	A a;
	B b;
	C c;

	f(&a);
	f(&b);
	f(&c);

	return 0;
}

#endif

/// Object 포인터 Type이 동적으로 변경되면 dynamic binding 발생

#if 0

#include <iostream>
using namespace std;

class A
{
public:
	virtual void f() { cout << "A" << endl; }
};

class B : public A
{
public:
	virtual void f() override { cout << "B" << endl; }
};

class C : public B
{
public:
	virtual void f() override { cout << "C" << endl; }
};

void f(A * p)
{
	p->f();
}

int main()
{
	A a;
	B b;
	C c;

	f(&a);
	f(&b);
	f(&c);

	return 0;
}

#endif

// Run time type 확인으로 static binding이 되도록 설계

#if 0

#include <iostream>
using namespace std;

class A
{
public:
	virtual void f() { cout << "A" << endl; }
};

class B : public A
{
public:
	virtual void f() override { cout << "B" << endl; }
};

class C : public B
{
public:
	virtual void f() override { cout << "C" << endl; }
};

void f(A * p)
{
	const type_info & t = typeid(*p);
	cout << t.name() << endl;

	if (typeid(*p) == typeid(A))	p->A::f();
	else p->f();

	((C *)p)->C::f();
}

int main()
{
	A a;
	B b;
	C c;

	f(&a);
	f(&b);
	f(&c);

	return 0;
}

#endif

// 멤버 함수에 의한 Operator Overloading

#if 0

#include <iostream>
using namespace std;

class A
{
public:
	int a;

	A(int x = 0) : a(x) {};

	int operator+(A y)
	{
		return this->a - y.a;
	}
};

int main()
{
	A x(10);
	A y(20);
	A z = x + y; // z(x + y)

	cout << x.a << " " << y.a << " " << z.a << endl;

	return 0;
}

#endif

// 외부 함수에 의한 Operator Overloading

#if 0

#include <iostream>
using namespace std;

class B
{
public:
	int a;

	friend B operator*(const B& x, int y);
};

B operator*(const B& x, int y)
{
	B r;
	r.a = x.a + (y * 2);
	return r;
}

int main()
{
	B m;
	B n;
	m.a = 20;
	n = m * 5;

	cout << n.a << endl;

	return 0;
}

#endif

// 재정의한 연산자의 Cascading 연산

#if 0

#include <iostream>
using namespace std;

class myout
{
public:
	int n;

	myout(int in = 0) : n(in) {}

	myout operator<<(int m)
	{
		this->n += m;
		return *this;
	}
};

int main()
{
	myout x;

	cout << (x << 10 << 20 << 30).n << endl;

	return 0;
}

#endif

// STL의 이해 : string class

#if 0

#include <iostream>
#include <string>
using namespace std;

int main()
{
	string s1 = "Hello";
	string s2 = "C++";
	string s3 = s1 + " " + s2;

	cout << s3 << endl;

	s3 = "World";
	cout << s3 << endl;

	cout << s1[2] << endl;

	if (s3 == "World") cout << "SAME" << endl;

	return 0;
}

#endif

// Sequnece Type Container 종류와 기본 특징

#if 0

#include <iostream>
using namespace std;

#include <vector>
#include <list>
#include <deque>

int main()
{
	//vector<int> a;
	//list<int> a;		// 리스트는 인덱싱 불가 2, 3 번째 for문 에러
	deque<int> a;

	for (int i = 0; i < 4; i++) a.push_back(i);
	for (int i = 0; i < 4; i++) cout << a[i] << endl;
	for (int i = 0; i < 4; i++) cout << a.at(i) << endl;
	for (auto &x : a) cout << x << endl;

	a.pop_back();
	for (auto &x : a) cout << x << endl;

	a.pop_front();		// vector는 pop_front 할 수 없음
	cout << a.front() << endl;

	a.pop_back();
	cout << a.back() << endl;

	return 0;
}

#endif

// Iterator와 insert(), erase()

#if 0

#include <iostream>
using namespace std;

#include <vector>
#include <list>
#include <deque>

#define CONT_TYPE	vector
//#define CONT_TYPE	deque
//#define CONT_TYPE	list

int main()
{
	CONT_TYPE<int> a;
	CONT_TYPE<int>::iterator p;

	for (int i = 0; i < 3; i++) a.push_back(i);
	for (int i = 0; i < 3; i++) cout << *(a.begin() + i) << endl;
	for (p = a.begin(); p != a.end(); p++) cout << *p << endl;

	p = a.begin();
	cout << *(p + 1) << endl;

	p = a.insert(p + 1, -1);
	cout << *p << endl;

	p = a.begin();
	cout << *(p + 1) << endl;
	cout << *p << endl;

	a.erase(p + 2);
	for (p = a.begin(); p != a.end(); p++) cout << *p << endl;

	return 0;
}

#endif

// Associative Container 종류와 기본 특징 : set

#if 0

#include <iostream>
using namespace std;

#include <set>

int main()
{
	set<int> a = { 1,3,-2, 3, 5 };

	a.insert(10);
	a.insert(3);
	a.erase(5);

	cout << "SIZE = " << a.size() << endl;
	for (auto &x : a) cout << x << endl;

	auto y = a.find(3);

	if (y != a.end()) cout << "IN" << endl;
	else cout << "NOT IN" << endl;

	return 0;
}

#endif

// Associative Container 종류와 기본 특징 : map

#if 0

#include <iostream>
using namespace std;

#include <map>
#include <string>

int main()
{
	map<string, int> a = { make_pair("Banana", 190), {"Grape", 285} };

	a["Apple"] = 100;
	a["Orange"] = 200;
	a["Kiwi"] = 80;

	a.insert(make_pair("Lemon", 120));
	a.erase("Orange");

	cout << "SIZE = " << a.size() << endl;	// 6 - 1 = 5
	cout << a["Apple"] << endl;
	cout << a["Orange"] << endl;	// erase 값을 0으로 만든다(다시 만들 수도 있어서) 갯수 계산에는 포함되지 않는다

	for (auto p : a) cout << p.first << " " << p.second << "\n"; // orange 0으로 출력됨

	auto y = a.find("Kiwi");

	if (y != a.end()) cout << "IN" << endl;
	else cout << "NOT IN" << endl;

	return 0;
}

#endif

// stack 구현 예시

#if 0

#include <iostream>
using namespace std;

#include <stack>

int main()
{
	stack<int> a;

	a.push(5);
	a.push(4);

	cout << a.top() << endl;
	a.pop();

	a.push(3);
	cout << a.size() << endl;

	while (!a.empty())
	{
		cout << a.top() << endl;
		a.pop();
	}

	return 0;
}

#endif

// Queue 구현 예시

#if 0

#include <iostream>
using namespace std;

#include <queue>

int main()
{
	queue<int> a;

	a.push(5);
	a.push(4);

	cout << a.front() << endl;
	a.pop();

	a.push(3);
	cout << a.size() << endl;

	while (!a.empty())
	{
		cout << a.front() << endl;
		a.pop();
	}

	return 0;
}

#endif

// Lambda Expression: capture list

#if 0

#include <iostream>
using namespace std;

int main()
{
	int a = 10; int b = 20;

	auto f1 = [](int x, int y)->int {return x + y; };
	auto f2 = [a, b](int x, int y)->int {return x + y + a + b; };
	auto f3 = [&a](int x, int y)->int {return x + y + a; };
	auto f4 = [=](int x, int y)->int {return x + y + b; };
	auto f5 = [&](int x, int y = 5)->int {return x + y + b; };

	a = 30;

	cout << f1(3, 4) << endl;	// 7
	cout << f2(3, 4) << endl;	// 37
	cout << f3(3, 4) << endl;	// 37
	cout << f4(3, 4) << endl;	// 27
	cout << f5(3) << endl;		// 28

	return 0;
}

#endif

// Lambda Expression: 임시함수 생성

#if 0

#include <iostream>
using namespace std;

int main()
{
	int a = 10; int b = 20;

	int r1 = [a, b](int x, int y)->int {return x + y + a + b; }(3, 4);
	int r2 = [&a](int x, int y)->int {return x + y + a; }(3, 4);
	int r3 = [=](int x, int y)->int {return x + y + b; }(3, 4);
	int r4 = [&](int x, int y)->int {return x + y + b; }(3, 4);

	cout << r1 << ":" << r2 << ":" << r3 << ":" << r4 << endl;

	return 0;
}

#endif

// Lambda Expression의 활용 : call back

#if 0

#include <iostream>
using namespace std;

template <typename T>
void func(T f)
{
	cout << f(3, 4) << endl;
}

int main()
{
	func([](int x, int y)->int {return x + y; });

	return 0;
}

#endif

// algorithm sort 함수에 사용한 lambda expression 활용 예

#if 0

#include <iostream>
using namespace std;

#include <string>
#include <vector>
#include <algorithm>

int main()
{
	vector<pair<string, int>> x = { {"Peach", 290},{"Grape", 310},{"Apple", 300},{"Banana", 290} };

	for (const auto & y : x) cout << y.first << ":" << y.second << endl;
	cout << "-----------------" << endl;

	//sort(x.begin(), x.end());
	//sort(x.begin(), x.end(), [](auto x, auto y)->bool {return x.first > y.first; });
	//sort(x.begin(), x.end(), [](auto x, auto y)->bool {return x.second < y.second;});
	sort(x.begin(), x.end(), [](auto x, auto y)->bool {return x.second > y.second; });	// 가격이 같을 경우 이름 오름차순으로 정렬
	//sort(x.begin(), x.end(), [](auto x, auto y)->bool {return (x.second == y.second)?(x.first < y.first): (x.second > y.second);});

	for (const auto & y : x) cout << y.first << ":" << y.second << endl;

	return 0;
}

#endif

// map의 value에 의한 정렬

#if 0

#include <iostream>
using namespace std;

#include <map>
#include <string>
#include <vector>
#include <algorithm>

int main()
{
	map<string, int> m = { {"Peach", 290},{"Grape", 310},{"Apple", 300},{"Banana", 290} };
	vector<pair<string, int>> x;

	for (const auto & y : m) x.push_back(y);

	for (const auto & y : x) cout << y.first << ":" << y.second << endl;
	cout << "-----------------" << endl;

	sort(x.begin(), x.end(), [](auto x, auto y)->bool {return x.second < y.second; });

	for (const auto & y : x) cout << y.first << ":" << y.second << endl;

	return 0;
}

#endif
