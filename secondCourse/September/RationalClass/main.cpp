#include <iostream>
#include "../Lib/Rational.h"

using namespace std;

int main() {
	Rational a = Rational (5, 6);
	Rational b = 3;
	Rational c = a + 2;
	Rational d = 2 + b;
	Rational e = -b - c;
	Rational f = c * 2 * c;
	cout << a << endl << b << endl << c << endl << d << endl << e << endl << f << endl;
	
	return 0;
}
