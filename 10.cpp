#include <iostream>
#include <cmath>
using namespace std;

class Figura {
public:
	virtual ~Figura() {}
	virtual double pole() const = 0;
	virtual double obwod() const = 0;
};

class Trapez : public Figura {
protected:
	double a, b, c, d, h;
public:
	Trapez(double a, double b, double c, double d, double h) : a(a), b(b), c(c), d(d), h(h) {}
	double pole() const override {
		return (a+b)*h / 2;
	}
	double obwod() const override {
		return a+b+c+d;
	}
};

class Rownoleglobok : public Trapez
{
protected:
	double alfa;
public:
	Rownoleglobok(double a, double b, double h, double alfa) : Trapez(a, a, b, b, h), alfa(alfa) {}
	double pole() const override
	{
		return a * c * sin(alfa * M_PI / 180.0);
	}
	double obwod() const override
	{
		return 2 * (a + c);
	}
};

class Prostokat : public Rownoleglobok {
public:
	Prostokat(double a, double b) : Rownoleglobok(a, b, b, 90) {}
};


class Czworokat : public Figura
{
protected:
	double a, b, e, f;
public:
	Czworokat(double a, double b, double e, double f) : a(a), b(b), e(e), f(f) {}
	double pole() const override
	{
		return e * f / 2;
	}
	double obwod() const override
	{
		return 2 * (a + b);
	}
};


class Romb : public Rownoleglobok, public Czworokat {
public:
	Romb(double a, double b, double e, double f) : Rownoleglobok(a, a, e, f), Czworokat(a, a, e, f) {}
	Romb(double e, double f) : Rownoleglobok(0, 0, e, 0), Czworokat(0, 0, e, f) {}
	Romb(double a, double h, double alfa) : Rownoleglobok(a, a, h, alfa), Czworokat(a, a, 0, 0) {}

	double pole() const override {
		return Czworokat::pole();
	}
	double obwod() const override {
		return Rownoleglobok::obwod();
	}
};


class Kwadrat : public Romb {
public:
	Kwadrat(int a) : Romb(a, a * a, a, a) {}
};

int main() {
	Kwadrat k1(2);
	cout << "Pole kwadratu: " << k1.pole() << endl;
	cout << "Obwod kwadratu: " << k1.obwod() << endl;

	Prostokat p(3, 4);
	cout << "Pole prostokata: " << p.pole() << endl;
	cout << "Obwod prostokata: " << p.obwod() << endl;

	Romb r(5, 12, 6, 8);
	cout << "Pole rombu: " << r.pole() << endl;
	cout << "Obwod rombu: " << r.obwod() << endl;

	return 0;
}