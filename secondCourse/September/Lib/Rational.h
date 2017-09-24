#include <iostream>
using namespace std;

class Rational {
	private:
		int num;
		int den;
	public:
		Rational();
		Rational(int);
		Rational(int, int);
		friend Rational operator + (int, Rational); friend Rational operator - (int, Rational);
		friend Rational operator * (int, Rational); friend Rational operator / (int, Rational);
		
		Rational operator + (Rational); Rational operator - (Rational);
		Rational operator * (Rational); Rational operator / (Rational);
		bool operator < (Rational); bool operator > (Rational);
		bool operator == (Rational); bool operator != (Rational);
		Rational& operator += (Rational); Rational& operator -= (Rational);
		Rational& operator *= (Rational); Rational& operator /= (Rational);
		friend ostream& operator << (ostream&, const Rational&);
		Rational operator - ();
		void reduce();
};
