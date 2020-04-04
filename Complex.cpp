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
	friend istream& operator >>(istream& is, const Complex& b);

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
	Re = complex.Re;
	Im = complex.Im;
}

void Complex::SetComplex(double Re, double Im) {
	this->Re = Re;
	this->Im = Re;
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
	Re = b.Re;
	Im = b.Im;
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

istream& operator >>(istream& is, const Complex& b) {
	is >> b.Re;
	is >> b.Im;
	return is;
}



int main() {
	setlocale(LC_ALL, "ru");
	Complex a;
	Complex b(23, 92);
	Complex c(b);
	c.SetComplex(124, -1);
	cout << "Конструктор по умолчанию : " << a << endl << "Конструктор инициализации : " << b << endl << "Конструктор копирования : " << c << endl << "Доступ к защищенным полям класса : " << c.GetComplex() << endl;
	Complex d = a + b;
	cout << "+ : " << d << endl;
	Complex e = a - b;
	cout << "- : " << e << endl;
	Complex f = a * b;
	cout << "* : " << f << endl;
	Complex g = a / b;
	cout << "/ : " << g << endl;
	Complex h = b;
	cout << "= : " << h << endl;
	bool i = a == b;
	cout << "== : " << i << endl;
	bool j = a != b;
	cout << "!= : " << j << endl;
	Complex k(-9, 4);
	cout << "<< : " << k << endl;
	Complex l;
	cin >> l;
	cout << ">> : " << l << endl;
}
