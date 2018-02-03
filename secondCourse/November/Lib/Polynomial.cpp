#include <iostream>
#include "Polynomial.h"
using namespace std;

Polynomial::Polynomial() {
	number = 0;
	coefficients = 0;
}

Polynomial::Polynomial(int n, int x) {
	number = n;
	coefficients = new int[number];
	for (int i = 0; i < number; i++)
		coefficients[i] = x;
}

Polynomial::Polynomial(int n, const int* pol) {
	number = n;
	coefficients = new int[number];
	for (int i = 0; i < number; i++)
		coefficients[i] = pol[i];
}

Polynomial::Polynomial(const Polynomial& pol) {
	number = pol.number;
    coefficients = new int[number];
    for (int i = 0; i < number; i++)
        coefficients[i] = pol.coefficients[i];
}

Polynomial::~Polynomial() {
	delete[] coefficients;
}

int Polynomial::degree() {
	return number - 1;
}

int Polynomial::operator [](int k) {
	return coefficients[k];
}

int Polynomial::operator ()(int x) {
	int p = coefficients[number - 1];
	for (int i = number - 2; i >= 0; i--)
		p = coefficients[i] + p * x;
	return p;
}

Polynomial Polynomial::operator + (const Polynomial& pol) {
	int n = (pol.number < number) ? number : pol.number;
	int* result = new int[n];
	if (number == pol.number) {
	    for(int i = 0; i < number; i++)
			result[i] = pol.coefficients[i] + coefficients[i];
		return Polynomial(n, result);
	}
	else if (number > pol.number) {
		for(int i = 0; i < pol.number; i++)
	    	result[i] = pol.coefficients[i] + coefficients[i];
	    for(int i = pol.number; i < number; i++)
	    	result[i] = coefficients[i];
	    return Polynomial(n, result);
	}
	else {
		for(int i = 0; i < number; i++)
	    	result[i] = pol.coefficients[i] + coefficients[i];
	    for(int i = number; i < pol.number; i++)
	    	result[i] = pol.coefficients[i];
	    return Polynomial(n, result);
	}
}

Polynomial& Polynomial::operator += (const Polynomial& pol) {
	*this = (*this) + pol;
	return *this;
}

Polynomial Polynomial::operator * (const Polynomial& pol) {
	if (pol.number == 0 || number == 0)
       return Polynomial();
    int n = number + pol.number;
    int* result = new int[n];
    for(int i = 0; i < n; i++) 
		result[i] = 0;
	for(int i = 0; i < pol.number; i++)
	    for(int j = 0; j < number; j++) 
			result[i + j] += pol.coefficients[i] * coefficients[j];
	return Polynomial(n, result);
}

Polynomial Polynomial::operator *= (const Polynomial& pol) {
	*this = (*this) * pol;
	return *this;
}

Polynomial& Polynomial::operator = (const Polynomial& pol) {
	number = pol.number;
	delete []coefficients;
	coefficients = new int[number];
	for(int i = 0; i < number; i++)
		coefficients[i] = pol.coefficients[i];
	return *this;
}

bool Polynomial::operator == (const Polynomial& pol) {
    if(number != pol.number)
    	return false;           	
    int i = 0;
    while(i < number)
        if(coefficients[i] != pol.coefficients[i])
            return false;
        else i++;
    return true;
}

bool Polynomial::operator != (const Polynomial& pol) {
	return !(*this == pol);
}

Polynomial Polynomial::operator * (int x) {
	if (x == 0)
    	return Polynomial();
   	int* result = new int[number];
    for(int i = 0; i < number; i++)
        result[i] = coefficients[i] * x;
    return Polynomial(number, result);
}

Polynomial Polynomial::operator *= (int x) {
	if(x == 0) {
		*this = Polynomial();
		return *this;
    }
	for(int i = 0; i < number; i++)
        coefficients[i] *= x;
    return *this;
}
