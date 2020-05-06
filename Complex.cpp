#include <iostream>
using namespace std;


class Complex {
	double Re;
	double Im;
public:
	Complex();
	Complex(double Re, double Im);
	Complex(Complex& complex);
	void SetComplex(double Re, double Im);
	Complex GetComplex();
	Complex operator+(const Complex& b);
	Complex operator-(const Complex& b);
	Complex operator*(const Complex& b);
	Complex operator/(const Complex& b);
	Complex& operator=(const Complex& b);
	bool operator == (const Complex& b);
	bool operator != (const Complex& b);
	friend ostream& operator <<(ostream& os, const Complex& b);
	friend istream& operator >>(istream& is, Complex& b);

};

Complex::Complex() {
	Re = 7;
	Im = -2;
}

Complex::Complex(double Re, double Im) {
	this->Re = Re;
	this->Im = Im;
}

Complex::Complex(Complex& complex) {
	this->Re = complex.Re;
	this->Im = complex.Im;
}

void Complex::SetComplex(double Re, double Im) {
	this->Re = Re;
	this->Im = Im;
}

Complex Complex::GetComplex() {
	Complex temp(Re, Im);
	return temp;
}

Complex Complex:: operator+(const Complex& b) {
	Complex temp;
	temp.Re = Re + b.Re;
	temp.Im = Im + b.Im;
	return temp;
}

Complex Complex:: operator-(const Complex& b) {
	Complex temp;
	temp.Re = Re - b.Re;
	temp.Im = Im - b.Im;
	return temp;
}
Complex Complex:: operator*(const Complex& b) {
	Complex temp;
	temp.Re = Re * b.Re - Im * b.Im;
	temp.Im = Re * b.Im + Im * b.Re;
	return temp;
}
Complex Complex:: operator/ (const Complex& b) {
	Complex temp;
	temp.Re = (Re * b.Re + Im * b.Im) / (b.Re * b.Re + b.Im * b.Im);
	temp.Im = (b.Re * Im - Re * b.Im) / (b.Re * b.Re + b.Im * b.Im);
	return temp;
}
Complex& Complex:: operator= (const Complex& b) {
	if (this != &b) {
		Re = b.Re;
		Im = b.Im;
	}
	return *this;
}

bool Complex:: operator== (const Complex& b) {
	return (Re = b.Re && Im == b.Im);
}

bool Complex:: operator!= (const Complex& b) {
	return !(Re = b.Re && Im == b.Im);
}

ostream& operator <<(ostream& os, const Complex& b) {
	os << b.Re << " " << b.Im << endl;
	return os;

}

istream& operator >>(istream& is, Complex& b) {
	is >> b.Re;
	is >> b.Im;
	return is;
}



int main() {
	setlocale(LC_ALL, "ru");
	Complex a;
	Complex b(23, 92);
	Complex c(b);
	cout << "Конструктор по умолчанию : " << a << endl << "Конструктор инициализатор : " << b << endl << "Конструктор копирования : " << c << endl;
	c.SetComplex(124, -1);
	cout << "Доступ к защищенным полям : " << c.GetComplex() << endl;
	Complex d;
	d = a + b;
	cout << "+ : " << d << endl;
	Complex e;
	e = a - b;
	cout << "- : " << e << endl;
	Complex f;
	f = a * b;
	cout << "* : " << f << endl;
	Complex g;
	g = a / b;
	cout << "/ : " << g << endl;
	Complex h;
	h = a = b;
	cout << "= : " << h << endl;
	bool i = a == b;
	cout << "== : " << i << endl;
	bool j = a != b;
	cout << "!= : " << j << endl;
	Complex k(-9, 4);
	cout << "<< : " << k << endl;
	Complex l;
	cout << "Введите комплексное число" << endl;
	cin >> l;
	cout << ">> : " << l << endl;
}