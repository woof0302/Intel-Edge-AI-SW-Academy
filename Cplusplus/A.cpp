// ���� ai sw ���� C++ OOP ����  ����� ������ ���� (2024.12.24 ~ 2025.1.3) ���� �� ���� ���� Ǯ�� �� �ּ�


#include <iostream>
using namespace std;

// A0 p.19 ---------------------------------------------------
// 10���� ���� �Է� �޾� 16������ �μ��ϱ�
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
//10���� 1��, 16���� 1�� ������ �Է¹޾� �հ踦 10������ �μ��ϱ�
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
//�ִ� 20���� ���ڿ� �Է� �޾Ƽ� ù ����, ������ ���� �μ��ϱ�
#if 0

#include <iostream>
#include <cstring>
using namespace std;

int main()
{
	char s[21]; // �ι��ڱ��� �ϴ� ��ƾ��ؼ� 21���� ��ƾ��Ѵ�.

	cin >> s;
	cout << s[0] << endl;
	cout << s[strlen(s) - 1] << endl;

	return 0;
}

#endif

// A3 p.20 ---------------------------------------------------
// ���� 1���� �� �ܾ �Է� �޾Ƽ� 2��° �ܾ �Է� ���� ���� ��ŭ �μ��ϱ�
#if 0

// cin �� white space �������� �����ؼ� ��������

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

	while (*(s + pos++) != ' ');  // *(s + pos++)  ���� ������ �ƴ� ���� pos�� ����

	while (n--)
	{
		cout << (s + pos) << endl;	// �� ��° �ܾ� n�� ���
	}

	return 0;
}

// �ι�° ���

int main()
{
	int n;
	char s[21];

	cin >> n;
	cin >> s;
	cin >> s;	// s�� �ι� �Է¹����� �ι�° �ܾ �����ְ� �ȴ�

	for (int i = 0; i < n; i++)
	{
		cout << s << endl;
	}
}

#endif

// A4 p.22 ---------------------------------------------------
// ��ǰ���ݰ� ������(�Ǽ� r)�� ���� ������ ��ǰ���ݿ� �������� �ݿ��� ������ ��ȯ�ϴ� �Լ� compute_price
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
// ������ Ÿ�Կ� ���� �ٸ��� �����ϴ� �Լ� �����
#if 0

#include <iostream>
using namespace std;

//  �Լ� ����
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
// �����Ҵ� �޾Ƽ� �Է� ���� ���� �� �ִ밪 ���ϱ�
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

	int max = p[0];		// ���� ���� �����ϰ� �Լ� ����°� ���� 

	for (i = 1; i < n; i++) // 0�� ���� �ʿ䰡 ���� (������ p[0]���� �����ϱ�)
	{
		if (max < p[i])
		{
			max = p[i];
		}
		
	}

	cout << max;

	delete[] p;  // ��ȯ �������� �ȵ� !!
}

#endif

// A7 p.26 ---------------------------------------------------
// func ȣ�� �� ����ü s�� ��� b�� ���� �Է¹��� ���ڷ� ����ǵ��� �ϱ� ���� �Լ� func�� �����϶�.
#if 0

#include <iostream>
using namespace std;

// �Լ� ����
// 1 ��
void func(char &a, int n)
{
	a = (char)n;

}
// 2 ����
void func(char &x, char c) // �Ű������� char������ �޾Ƽ� ���� �� �ٷ� ����ȯ
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
// raged for�� �̿��Ͽ� �迭�� ����� ������ ��� �μ��ϱ�
#if 0

#include <iostream>
using namespace std;

// �Լ� ����
template <typename T>
void func(T &a)		// call by reference�� ȣ�� (�μ��� �ѱ� ������ ������ ������ִ� ����)
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
// �����̺� ��� ���� �� �ٲٱ�
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
	// class�� private ���� tax�� ���� ���� ������ ����
	mart_calc::tax = tax;		// mart_calc::tax  mart_clacŬ������ tax��� ���� �������ָ� �ȴ�
								// this -> tax = tax; �ε� ���� p.38
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
// Default Parameter�� �̿��� buy ����Լ� ����
#if 0

class mart_calc
{
public:
	double total = 0;
	void buy(int price, double tax = 0.01); // ����ο� default �� ����
};

// member function buy ����

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
// Instance ������ ����, �ʱ�ȭ, Ȱ��
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

	// &x�� �ʱ�ȭ�� �ϴ� ������ p ����
	test* p = &x;	// test * p(&x);

	cout << x.a << endl;

	// ������ p�� �̿��Ͽ� instance x�� a�� �μ�
	cout << (*p).a << endl;		// p -> a  �� ����

	return 0;
}

#endif

// B2 p.45 ---------------------------------------------------
// Instance 2���� ���� �迭 ����� Ȱ��
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
	// test class�� instance 2���� ���� �迭 y�� �����ϰ� 
	// �� instance�� �ʱ�ȭ ������ 10, 20�� ���� �ǵ��� �϶�.

	test y[2] = { 10, 20 };

	// �迭 y�� ��� instance ���� ��� ������ a�� �μ��ϴ� �ڵ带 �ۼ��϶�.
	cout << y[0].a << endl << y[1].a;

	return 0;
}

#endif

// B3 p.45 ---------------------------------------------------
// Instance�� ��ҷ� ���� ����ü ����� Ȱ��
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
	// st ����ü template�� ���� z ����
	// ����ü z�� ��� m1�� ���� 10���� �ʱ�ȭ
	// ����ü z�� ��� m2 instance�� �ʱⰪ���� 20 ����

	st z = { 10, 20 };

	// ����ü z�� ��� m1�� m2�� a �� �μ�

	cout << z.m1 << endl << z.m2.a;

	return 0;
}

#endif

// B4 p.46 ---------------------------------------------------
// ����� �Ǹŷ�, �Ǹžװ� ��ü �Ǹŷ�, �Ǹž��� �����ϴ� class ����
#if 0

class SALES
{
public:
	SALES(int sales, int volume)  // ������
	{
		this->sales = sales;
		this->volume = volume;
		this->whole_sales += sales;
		this->whole_volume += volume;
	}

	void sales_report(int sales, int volume);

	void print_report();

private:

	static int whole_sales; // ��ü �Ǹż���
	static int whole_volume; // ��ü �Ǹűݾ�

	int sales = 0; // �Ǹż���
	int volume = 0; // �Ǹűݾ�						// ��� function�� ���� �������. member data ���� �����ϴ� ������ ����
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

// ����
#if 0

class SALES
{
private:
	static int count;		//member data ���� ������ ���� �� �� �ִ�.
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
// ���κ� ������ ��ü ������ ���� �μ��ϴ� �Լ� ���� ����
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

	static void total_report() // ::�����ڷ� �����ϱ� ���ؼ� static���� ����
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
//��� ��� age, name�� instance ������ ���޵Ǵ� ������ �ʱ�ȭ�ǵ��� �ڵ带 �����϶�.
#if 0

class student
{
public:
	const int age;
	const char* name;

	student(int a, const char* n) : age(a), name(n)  // �ʱ�ȭ ����Ʈ�� ����ؾ� �Ѵ�. ���� �� �ٷ� �ʱ�ȭ
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
// Const Instance���� ��� �����͸� read-only�� ����ϴ� ��� �Լ��� ȣ��
#if 0

class student
{
public:
	int age;

	student(int a) : age(a) {}

	int func() const		// const �� �ٿ��ָ� 
	{
		cout << age << endl;
		return age;
	}
};

int main(void)
{
	const student x(10);

	int r = x.func();		// ȣ�� ����

	cout << r << endl;

	return 0;
}

#endif

// B8 p.55 ---------------------------------------------------
// Derived Class ����
#if 0

class figure
{
private:
	int color_index;

public:
	void set_color(int ci)	//�Ű������� ��������� ���� �̸��϶�
	{
		color_index = ci;	// this->color_index = color_index;  this �� ���ذ� �������  �����ϴ� ���� �Ű������� �ִ� ��
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
		this->radius = a;	// �̸� �ٸ� ���� this �Ⱦ��� radius = a; �ص��ȴ�.
		set_color(b);		// color_index =ci;   private�� ��� ���ؿ� set_color(), get_color() �� �޾ƿ�
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
// Derived Class�� ��� ��� ���ټ� ���� 
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
// friend ������ ���� ��ȣ�� ����� ���� ��� (58)
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
// Base Class�� ������ ȣ�� 1 (61)
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

	// ������ ����
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
// Base Class�� ������ ȣ�� 2 (61)
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

	// ������ ����
	circle(const char* s, int r) :radius(r), figure(s)  // ���� �ٲ� ���� / radius const�� �� ������θ� �ʱ�ȭ ����
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
// Base Class�� ��� �����͸� �μ��ϴ� �Լ� ���� (63)
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

// �Լ� ����
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
// Derived Class�� ��� �����͸� �μ��ϴ� �Լ� ���� 1 (64)
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
	// ���޹��� r �ּҸ� �̿��Ͽ� r�� height �μ�	
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
// Derived Class�� ��� �����͸� �μ��ϴ� �Լ� ���� 2 (64)
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
	// ���޹��� r�� reference�� �̿��Ͽ� r�� height �μ�
	cout << ((rectagle*)&x)->height;		// �Ű������� ���� &x�� figure ������ó�� �ٷ�� �ȴ�.
}

int main()
{
	rectagle r(2, 20, 30);

	prt_height(r);

	return 0;
}

#endif


// C6 ---------------------------------------------------
// ��� �Լ� Overriding (71)
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

	// prt_size �Լ� ����
	virtual void prt_size()			// virtual ������
	{
		cout << this->width << endl;
	}
};

class rectagle : public square		// ����ٰ� virtual�� ����
{
public:
	int height;

	rectagle(int c, int w, int h) : square(c, w), height(h) {}

	// prt_size �Լ� ����
	virtual void prt_size()	override	// virtual ������ override�� ���̴� ������ �Լ����� �߸� ġ�� ���� �޸� ������ ������ �� �ִ�.
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
// virtual function�� �̿��� Polymorphism ���� (73)
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
// ������ overloading (80)
#if 0

class box
{
public:
	int width;
	int height;

	box(int w, int h) : width(w), height(h) {}

	// �ڵ� ����
	box operator+(const box& b)
	{
		int w, h;
		w = this->width + b.width;
		h = this->height + b.height;
		return box(w, h);

		// box x(this->width + y.width, this->height + y.height)  ������ �ڵ� 
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
// �ܺ� �Լ��� ���� �پ��� ������ overloading (81)
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

// �Լ� ����

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
// Cascading�� ��� ���޵� insance�� ���� �����ϴ� ������ ������ �Լ� ���� (82)
#if 0

class myout
{
public:
	int n;

	myout(int in = 0) : n(in) {}

	myout& operator<<(int m)  // call by reference�� �Ѱܼ� ��ȯ ��� ����
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




