#include <iostream>
#include "Rational.h"

using namespace std;

int gcd(int a, int b) {
	return b ? gcd(b, a % b) : a;
}

void Rational::reduce() {
	int n = gcd(num, den);
	num /= n;
	den /= n;	
}

Rational::Rational() {
	num = 0;
	den = 1;
}

Rational::Rational(int x) {
	num = x;
	den = 1;
}

Rational::Rational(int x, int y) {
	num = x;
	den = y;
	if (y < 0) {
		num = -num;
		den = -den;	
	}
	reduce();
}

Rational Rational::operator + (Rational x) {
	return Rational(x.den * num + den * x.num, den * x.den);
}

Rational Rational::operator - (Rational x) {
	return Rational(x.den * num - den * x.num, den * x.den);
}

Rational Rational::operator * (Rational x) {
	return Rational(num * x.num, den * x.den);
}

Rational Rational::operator / (Rational x) {
	return Rational(num * x.den, den * x.num);
}

bool Rational::operator < (Rational x) {
    return x.den * num < den * x.num;
}

bool Rational::operator > (Rational x) {
    return x.den * num > den * x.num;
}

bool Rational::operator == (Rational x) {
    return x.den * num == den * x.num;
}

bool Rational::operator != (Rational x) {
    return x.den * num != den * x.num;
}

Rational& Rational::operator += (Rational x) {
    num *= x.den;
    num += den * x.num;
    den *= x.den;
    reduce();
    return *this;
}

Rational& Rational::operator -= (Rational x) {
    num *= x.den;
    num -= den * x.num;
    den *= x.den;
    reduce();
    return *this;
}

Rational& Rational::operator *= (Rational x) {
    num *= x.num;
    den *= x.den;
    reduce();
    return *this;
}

Rational& Rational::operator /= (Rational x) {
    num *= x.den;
    den *= x.num;
    reduce();
    return *this;
}

Rational Rational::operator -() {
    return Rational(-num);
}

ostream& operator << (ostream& rout, const Rational& x) {
    if (x.den == 1)
		rout << x.num;
	else
		rout << x.num << "/" << x.den;
	return rout;
}

Rational operator + (int x, Rational y) {
	return Rational(y + x);
}

Rational operator - (int x, Rational y) {
	Rational a = Rational(x);
	return Rational(a.den * y.num - a.num * y.den, a.den * y.den);
}

Rational operator * (int x, Rational y) {
	return Rational(y * x);
}

Rational operator / (int x, Rational y) {
	Rational a = Rational(x);
	return Rational(a.num * y.den, a.den * y.num);
}
