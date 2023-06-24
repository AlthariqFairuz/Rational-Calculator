#include<iostream>
using namespace std;
// Penambahan pecahan dengan OOP
class Rational
{
private:
	int p;
	int q;
public:
	Rational() {
		p = 1;
		q = 1;
	}
	Rational(int p, int q) {
		this->p = p;
		this->q = q;
	}
	Rational(Rational &r) {
		this->p = r.p;
		this->q = r.q;
	}
	int getP() { return p; }

	int getQ() { return q; }

	void setP(int p) {
		this->p = p;
	}

	void setQ(int q) {
		this->q = q;
	}

	Rational operator+(Rational r) {
		Rational result;
		result.p = this->p * r.q + r.p * this->q;
		result.q = this->q * r.q;
		return result;
	}

	friend ostream& operator<<(ostream &os, Rational &r);
};

ostream& operator<<(ostream &os, Rational &r)
{
	os << r.p << "/" << r.q;
	return os; // disini fungsi operator << sudah berubah, ia bisa nge print pecahan langsung tanpa harus di ketik manual satu2 komponen pecahannya
}

int main () {
	int firstNum;
	int firstDenom;
	int secondNum;
	int secondDenom;
	Rational r3;

	cout << "Input first numerator" << endl;
	cin >> firstNum;
	cout << "Input first denominator" << endl;
	cin >> firstDenom;
	Rational r1(firstNum, firstDenom);

	cout << "Input second numerator" << endl;
	cin >> secondNum;
	cout << "Input second denominator" << endl;
	cin >> secondDenom;
	Rational r2(secondNum, secondDenom);

	r3 = r1 + r2; // or u can also make r1.operator+(r2)
	cout << "Sum of " << r1 << " and " << r2 << " is " << r3 << endl;
}