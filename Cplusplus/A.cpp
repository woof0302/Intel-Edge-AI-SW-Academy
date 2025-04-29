// 인텔 ai sw 과정 C++ OOP 수업  류경식 교수님 강의 (2024.12.24 ~ 2025.1.3) 수업 중 연습 문제 풀이 및 주석


#include <iostream>
using namespace std;

// A0 p.19 ---------------------------------------------------
// 10진수 값을 입력 받아 16진수로 인쇄하기
#if 0

#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
	int a;
	cin >> a;
	cout << showbase << uppercase << hex << a;


	return 0;
}

#endif

// A1 p.19 ---------------------------------------------------
//10진수 1개, 16진수 1개 정수를 입력받아 합계를 10진수로 인쇄하기
#if 0

#include <iostream>
using namespace std;


int main()
{
	int x, y;

	cin >> x >> hex >> y;
	cout << x + y << endl;

	return 0;
}

#endif

// A2 p.20 ---------------------------------------------------
//최대 20글자 문자열 입력 받아서 첫 글자, 마지막 글자 인쇄하기
#if 0

#include <iostream>
#include <cstring>
using namespace std;

int main()
{
	char s[21]; // 널문자까지 일단 담아야해서 21개로 잡아야한다.

	cin >> s;
	cout << s[0] << endl;
	cout << s[strlen(s) - 1] << endl;

	return 0;
}

#endif

// A3 p.20 ---------------------------------------------------
// 정수 1개와 두 단어를 입력 받아서 2번째 단어를 입력 받은 정수 만큼 인쇄하기
#if 0

// cin 은 white space 기준으로 구분해서 가져간다

#include <iostream>
using namespace std;

int main()
{
	int n;
	int pos = 0;
	char s[21];

	cin >> n;
	cin.ignore();
	cin.getline(s, 20);

	while (*(s + pos++) != ' ');  // *(s + pos++)  값이 공백이 아닌 동안 pos값 증가

	while (n--)
	{
		cout << (s + pos) << endl;	// 두 번째 단어 n번 출력
	}

	return 0;
}

// 두번째 방법

int main()
{
	int n;
	char s[21];

	cin >> n;
	cin >> s;
	cin >> s;	// s에 두번 입력받으면 두번째 단어가 남아있게 된다

	for (int i = 0; i < n; i++)
	{
		cout << s << endl;
	}
}

#endif

// A4 p.22 ---------------------------------------------------
// 제품가격과 할인율(실수 r)을 전달 받으면 제품가격에 할인율을 반영한 가격을 반환하는 함수 compute_price
#if 0

#include <iostream>
using namespace std;

double compute_price(int price, double discount = 0.1)
{
	return price * (1 - discount);
}


int main()
{
	cout << compute_price(12000, 0.25) << endl;
	cout << compute_price(12000) << endl;
	cout << compute_price(32000, 0.1) << endl;

	return 0;
}

#endif

// A5 p.23 ---------------------------------------------------
// 데이터 타입에 따라 다르게 동작하는 함수 만들기
#if 0

#include <iostream>
using namespace std;

//  함수 설계
int func(int a)
{
	return a * a;
}

int func(double a)
{
	return (int)(a + 0.5);
}

double func(int a, double b)
{
	return a + b;
}

int main()
{
	cout << func(3) << endl;
	cout << func(3.49) << endl;
	cout << func(3.51) << endl;
	cout << func(10, 3.14) << endl;

	return 0;
}

#endif

// A6 p.25 ---------------------------------------------------
// 동적할당 받아서 입력 받은 값들 중 최대값 구하기
#if 0

#include <iostream>
using namespace std;

int main()
{
	int n, i;
	cin >> n;

	int *p = new int[n];

	for (i = 0; i < n; i++)
	{
		cin >> p[i];
	}

	int max = p[0];		// 변수 설계 먼저하고 함수 만드는걸 권장 

	for (i = 1; i < n; i++) // 0은 돌릴 필요가 없다 (위에서 p[0]으로 줬으니까)
	{
		if (max < p[i])
		{
			max = p[i];
		}
		
	}

	cout << max;

	delete[] p;  // 반환 빼먹으면 안됨 !!
}

#endif

// A7 p.26 ---------------------------------------------------
// func 호출 후 구조체 s의 멤버 b의 값을 입력받은 문자로 변경되도록 하기 위한 함수 func를 설계하라.
#if 0

#include <iostream>
using namespace std;

// 함수 설계
// 1 나
void func(char &a, int n)
{
	a = (char)n;

}
// 2 정답
void func(char &x, char c) // 매개변수를 char형으로 받아서 받을 때 바로 형변환
{
	x = c;
}

int main()
{
	struct _st
	{
		int a;
		char b;
	};

	_st s{ 100, 'A' };
	char n;

	cin >> n;
	func(s.b, n);

	cout << s.b << endl;

	return 0;
}

#endif

// A8 p.27 ---------------------------------------------------
// raged for를 이용하여 배열에 저장된 내용을 모두 인쇄하기
#if 0

#include <iostream>
using namespace std;

// 함수 설계
template <typename T>
void func(T &a)		// call by reference로 호출 (인수로 넘긴 값들의 별명을 만들어주는 거임)
{
	for (const auto &x : a) 
	{
		cout << x << endl; 
	}
}

func(T* x)
{
	ranged for (const T y : x);
}

int main()
{
	int a[3] = { 10,20,30 };
	const char * b[2] = { "Kim", "Lee" };

	func(a);
	func(b);

	return 0;
}

#endif

// A9 p.37 ---------------------------------------------------
// 프라이빗 멤버 변수 값 바꾸기
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
	mart_calc::tax = tax;		// mart_calc::tax  mart_clac클래스의 tax라는 것을 지정해주면 된다
								// this -> tax = tax; 로도 가능 p.38
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

// B0 p.40 ---------------------------------------------------
// Default Parameter를 이용한 buy 멤버함수 설계
#if 0

class mart_calc
{
public:
	double total = 0;
	void buy(int price, double tax = 0.01); // 선언부에 default 값 지정
};

// member function buy 설계

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

// B1 p.45 ---------------------------------------------------
// Instance 포인터 선언, 초기화, 활용
#if 0

class test
{
public:
	int a = 10;

	test(int b)
	{
		a += b;
	}
};

int main(void)
{
	test x(20);

	// &x로 초기화를 하는 포인터 p 선언
	test* p = &x;	// test * p(&x);

	cout << x.a << endl;

	// 포인터 p를 이용하여 instance x의 a값 인쇄
	cout << (*p).a << endl;		// p -> a  도 가능

	return 0;
}

#endif

// B2 p.45 ---------------------------------------------------
// Instance 2개를 갖는 배열 선언과 활용
#if 0

class test
{
public:
	int a = 10;

	test(int b)
	{
		a += b;
	}
};

int main(void)
{
	// test class의 instance 2개를 갖는 배열 y를 선언하고 
	// 두 instance의 초기화 값으로 10, 20이 전달 되도록 하라.

	test y[2] = { 10, 20 };

	// 배열 y의 요소 instance 들의 멤버 데이터 a를 인쇄하는 코드를 작성하라.
	cout << y[0].a << endl << y[1].a;

	return 0;
}

#endif

// B3 p.45 ---------------------------------------------------
// Instance를 요소로 갖는 구조체 선언과 활용
#if 0

class test
{
public:
	int a = 10;

	test(int b)
	{
		a += b;
	}
};

struct st
{
	int m1;
	test m2;
};

int main(void)
{
	// st 구조체 template의 변수 z 선언
	// 구조체 z의 멤버 m1은 정수 10으로 초기화
	// 구조체 z의 멤버 m2 instance의 초기값으로 20 전달

	st z = { 10, 20 };

	// 구조체 z의 멤버 m1과 m2의 a 값 인쇄

	cout << z.m1 << endl << z.m2.a;

	return 0;
}

#endif

// B4 p.46 ---------------------------------------------------
// 사원별 판매량, 판매액과 전체 판매량, 판매액을 관리하는 class 구현
#if 0

class SALES
{
public:
	SALES(int sales, int volume)  // 생성자
	{
		this->sales = sales;
		this->volume = volume;
		this->whole_sales += sales;
		this->whole_volume += volume;
	}

	void sales_report(int sales, int volume);

	void print_report();

private:

	static int whole_sales; // 전체 판매수량
	static int whole_volume; // 전체 판매금액

	int sales = 0; // 판매수량
	int volume = 0; // 판매금액						// 멤버 function을 먼저 만들었다. member data 먼저 설계하는 습관을 갖자
};

int SALES::whole_sales = 0;
int SALES::whole_volume = 0;

void SALES::sales_report(int sales, int volume)
{
	this->sales += sales;
	this->volume += volume;

	this->whole_sales += sales;
	this->whole_volume += volume;
}

void SALES::print_report()
{
	cout << this->whole_sales << endl;
	cout << this->whole_volume << endl;
	cout << this->sales << endl;
	cout << this->volume << endl;
}

int main()
{
	SALES a(5, 200);
	SALES b(2, 30);

	a.sales_report(7, 500);
	b.sales_report(9, 600);

	a.print_report();
	b.print_report();

	return 0;
}


#endif

// 정답
#if 0

class SALES
{
private:
	static int count;		//member data 먼저 선언한 것을 볼 수 있다.
	static int total;

	int my_count = 0;
	int my_total = 0;

public:
	SALES(int c, int t)
	{
		count += c;
		total += t;

		my_count += c;
		my_total += t;
	}

	void sales_report(int c, int t)
	{
		count += c;
		total += t;

		my_count += c;
		my_total += t;
	}

	void print_report()
	{
		cout << count << endl;
		cout << total << endl;
		cout << my_count << endl;
		cout << my_total << endl;
	}
};

int SALES::count = 0;
int SALES::total = 0;

int main()
{
	SALES a(5, 200);
	SALES b(2, 30);

	a.sales_report(7, 500);
	b.sales_report(9, 600);

	a.print_report();
	b.print_report();

	return 0;
}

#endif

// B5 p.47 ---------------------------------------------------
// 개인별 실적과 전체 실적을 따로 인쇄하는 함수 구분 설계
#if 0

class SALES
{
private:
	static int count;
	static int total;

	int my_count = 0;
	int my_total = 0;

public:
	SALES(int c, int t)
	{
		count += c;
		total += t;

		my_count += c;
		my_total += t;
	}

	void sales_report(int c, int t)
	{
		count += c;
		total += t;

		my_count += c;
		my_total += t;
	}

	void my_report()
	{
		cout << my_count << endl;	// <-
		cout << my_total << endl;
	}

	static void total_report() // ::연산자로 접근하기 위해서 static으로 정의
	{
		cout << count << endl;		// <-
		cout << total << endl;
	}
};

int SALES::count = 0;
int SALES::total = 0;

int main()
{
	SALES a(5, 200);
	SALES b(2, 30);

	a.sales_report(7, 500);
	b.sales_report(9, 600);

	a.my_report();
	b.my_report();
	SALES::total_report();

	return 0;
}

#endif

// B6 p. 48, 49---------------------------------------------------
//상수 멤버 age, name을 instance 생성시 전달되는 값으로 초기화되도록 코드를 수정하라.
#if 0

class student
{
public:
	const int age;
	const char* name;

	student(int a, const char* n) : age(a), name(n)  // 초기화 리스트를 사용해야 한다. 생성 시 바로 초기화
	{

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

// B7 p.51---------------------------------------------------
// Const Instance에서 멤버 데이터를 read-only로 취급하는 멤버 함수의 호출
#if 0

class student
{
public:
	int age;

	student(int a) : age(a) {}

	int func() const		// const 만 붙여주면 
	{
		cout << age << endl;
		return age;
	}
};

int main(void)
{
	const student x(10);

	int r = x.func();		// 호출 가능

	cout << r << endl;

	return 0;
}

#endif

// B8 p.55 ---------------------------------------------------
// Derived Class 생성
#if 0

class figure
{
private:
	int color_index;

public:
	void set_color(int ci)	//매개변수와 멤버변수가 같은 이름일때
	{
		color_index = ci;	// this->color_index = color_index;  this 를 써준게 멤버변수  대입하는 값이 매개변수로 주는 값
	}

	int get_color()
	{
		return color_index;
	}
};

class circle : public figure
{
private:
	int radius;
public:

	circle(int a, int b)
	{
		this->radius = a;	// 이름 다를 때는 this 안쓰고 radius = a; 해도된다.
		set_color(b);		// color_index =ci;   private은 상속 못해옴 set_color(), get_color() 만 받아옴
	}

	void info()
	{
		cout << get_color() << endl;
		cout << radius << endl;
	}

};

class box : public figure
{
private:
	int width;
	int height;

public:
	box(int a, int b, int c)
	{
		this->width = a;
		this->height = b;
		set_color(c);
	}

	void info()
	{
		cout << get_color() << endl;
		cout << width << endl;
		cout << height << endl;
	}
};

int main()
{
	circle c(5, 1);
	box b(10, 20, 2);

	c.info();
	b.info();

	return 0;
}

#endif

// B9 p.57 ---------------------------------------------------
// Derived Class의 상속 대상 접근성 지정 
#if 0

class A
{
public:
	int x = 10;
};

class B : public A
{
public:
	int y = 20;
};

class C : public B
{
public:
	int z = 30;
};

int main()
{
	C c;

	cout << c.x << endl;
	cout << c.y << endl;
	cout << c.z << endl;

	return 0;
}

#endif

// C0 ---------------------------------------------------
// friend 지정에 의한 보호된 멤버의 접근 허용 (58)
#if 0

class A
{
public:
	int x = 10;
};

class B : private A
{
public:
	int y = 20;

	friend class D; //
};

class C : protected B
{
public:
	int z = 30;

	friend void f(); //
};

class D
{
public:
	B b;

	void prt()
	{
		cout << b.x << endl;
	}

	friend int main(); //
};

void f()
{
	C c;
	cout << c.y << endl;
}

int main()
{
	D d;

	d.prt();
	f();

	return 0;
}

#endif

// C1 ---------------------------------------------------
// Base Class의 생성자 호출 1 (61)
#if 0

class figure
{
private:
	int color_index;

public:
	figure(int ci) : color_index(ci) {}

	int get_color()
	{
		return color_index;
	}
};

class circle : public figure
{
private:
	int radius;
public:

	// 생성자 설계
	circle(int r, int c) :figure(c)
	{
		this->radius = r;
	}

	void info()
	{
		cout << get_color() << endl;
		cout << radius << endl;
	}
};

int main()
{
	circle c(5, 1);
	c.info();
	return 0;
}

#endif

// C2 ---------------------------------------------------
// Base Class의 생성자 호출 2 (61)
#if 0

class figure
{
private:
	const char* color;

public:
	figure(const char* c) : color(c) {}

	const char* get_color()
	{
		return color;
	}
};

class circle : public figure
{
private:
	const int radius;
public:

	// 생성자 설계
	circle(const char* s, int r) :radius(r), figure(s)  // 순서 바뀌어도 무방 / radius const라서 저 방식으로만 초기화 가능
	{

	}

	void info()
	{
		cout << get_color() << endl;
		cout << radius << endl;
	}
};

int main()
{
	circle c("White", 1);
	c.info();
	return 0;
}

#endif
// C3 ---------------------------------------------------
// Base Class의 멤버 데이터를 인쇄하는 함수 설계 (63)
#if 0

class figure
{
public:
	int color_index;

	figure(int c) : color_index(c) {};
};

class circle : public figure
{
public:
	int radius;

	circle(int c, int r) : figure(c), radius(r) {};
};

class square : public figure
{
public:
	int width;

	square(int c, int w) : figure(c), width(w) {};
};

class rectagle : public square
{
public:
	int height;

	rectagle(int c, int w, int h) : square(c, w), height(h) {}
};

// 함수 설계
void prt_info(figure* p)	// upcasting
{
	cout << p->color_index << endl;
}

int main()
{
	circle c(0, 5);
	square s(1, 10);
	rectagle r(2, 20, 30);

	prt_info(&c);
	prt_info(&s);
	prt_info(&r);

	return 0;
}

#endif


// C4 ---------------------------------------------------
// Derived Class의 멤버 데이터를 인쇄하는 함수 설계 1 (64)
#if 0

class figure
{
public:
	int color_index;

	figure(int c) : color_index(c) {};
};

class square : public figure
{
public:
	int width;

	square(int c, int w) : figure(c), width(w) {};
};

class rectagle : public square
{
public:
	int height;

	rectagle(int c, int w, int h) : square(c, w), height(h) {}
};

void prt_height(figure* p)
{
	// 전달받은 r 주소를 이용하여 r의 height 인쇄	
	cout << ((rectagle*)p)->height; // downcasting
}

int main()
{
	rectagle r(2, 20, 30);
	prt_height(&r);
	return 0;
}

#endif


// C5 ---------------------------------------------------
// Derived Class의 멤버 데이터를 인쇄하는 함수 설계 2 (64)
#if 0

class figure
{
public:
	int color_index;

	figure(int c) : color_index(c) {};
};

class square : public figure
{
public:
	int width;

	square(int c, int w) : figure(c), width(w) {};
};

class rectagle : public square
{
public:
	int height;

	rectagle(int c, int w, int h) : square(c, w), height(h) {}
};

void prt_height(const figure& x)	//call by reference
{
	// 전달받은 r의 reference를 이용하여 r의 height 인쇄
	cout << ((rectagle*)&x)->height;		// 매개변수로 받은 &x를 figure 포인터처럼 다루면 된다.
}

int main()
{
	rectagle r(2, 20, 30);

	prt_height(r);

	return 0;
}

#endif


// C6 ---------------------------------------------------
// 멤버 함수 Overriding (71)
#if 0

class figure
{
public:
	int color_index;

	figure(int c) : color_index(c) {};
};

class square : public figure
{
public:
	int width;

	square(int c, int w) : figure(c), width(w) {};

	// prt_size 함수 설계
	virtual void prt_size()			// virtual 빼먹음
	{
		cout << this->width << endl;
	}
};

class rectagle : public square		// 여기다가 virtual을 붙임
{
public:
	int height;

	rectagle(int c, int w, int h) : square(c, w), height(h) {}

	// prt_size 함수 설계
	virtual void prt_size()	override	// virtual 빼먹음 override를 붙이는 것으로 함수명을 잘못 치는 등의 휴먼 에러를 방지할 수 있다.
	{
		cout << this->width << "*" << this->height << endl;
	}
};

int main()
{
	square s(1, 10);
	rectagle r(2, 20, 30);

	s.prt_size();
	r.prt_size();

	return 0;
}

#endif


// C7 ---------------------------------------------------
// virtual function을 이용한 Polymorphism 구현 (73)
#if 0

class figure
{
public:
	int color_index;

	figure(int c) : color_index(c) {};

	void virtual prt_info()		//
	{
		cout << color_index << endl;
	}
};

class square : public figure
{
public:
	int width;

	square(int c, int w) : figure(c), width(w) {};

	void virtual prt_info() override	//
	{
		cout << color_index << endl;
		cout << width << endl;
	}
};

class rectagle : public square
{
public:
	int height;

	rectagle(int c, int w, int h) : square(c, w), height(h) {}

	void virtual prt_info() override	//
	{
		cout << color_index << endl;
		cout << width << "*" << height << endl;
	}
};

void prt_info(figure* p)
{
	p->prt_info();
}

int main()
{
	square s(1, 10);
	rectagle r(2, 20, 30);

	prt_info(&s);
	prt_info(&r);

	return 0;
}

#endif

// D2 ---------------------------------------------------
// 연산자 overloading (80)
#if 0

class box
{
public:
	int width;
	int height;

	box(int w, int h) : width(w), height(h) {}

	// 코드 구현
	box operator+(const box& b)
	{
		int w, h;
		w = this->width + b.width;
		h = this->height + b.height;
		return box(w, h);

		// box x(this->width + y.width, this->height + y.height)  가람님 코드 
		// return x;

	}

	void prt_info()
	{
		cout << width << endl;
		cout << height << endl;
	}
};

int main()
{
	box a(3, 4);
	box b(10, 20);

	box c = a + b;
	c.prt_info();

	return 0;
}

#endif

// D3 ---------------------------------------------------
// 외부 함수에 의한 다양한 연산자 overloading (81)
#if 0

class box
{
public:
	int width;
	int height;

	box(int w, int h) : width(w), height(h) {}

	friend box operator+(const box& x, int i);
	friend box operator+(const box& x, const box& y);
	friend int operator*(const box& x);
};

// 함수 설계

box operator+(const box& x, int i)
{
	return box(x.width + i, x.height + i);
}

box operator+(const box& x, const box& y)
{
	return box(x.width + y.width, x.height + y.height);
}

int operator*(const box& x)
{
	return(x.width * x.height);
}

int main()
{
	box a(3, 4);
	box b(10, 20);

	box c = a + 5;
	cout << *c << endl;

	box d = a + b;
	cout << *d << endl;

	return 0;
}

#endif


// D4 ---------------------------------------------------
// Cascading될 경우 전달된 insance의 값을 변경하는 연산자 재정의 함수 설계 (82)
#if 0

class myout
{
public:
	int n;

	myout(int in = 0) : n(in) {}

	myout& operator<<(int m)  // call by reference로 넘겨서 반환 결과 공유
	{
		this->n += m;
		return *this;
	}
};

int main()
{
	myout x;

	cout << (x << 10 << 20 << 30).n << endl;
	cout << x.n << endl;

	return 0;
}

#endif




