#include <iostream>
#include "..\Lib\Polynomial.h"
using namespace std;

int main() {
	int a[4] = {4, -2, 3, 1};
	Polynomial p1 = Polynomial(4, a);
	Polynomial p2 = Polynomial(2, 1);
	Polynomial p3 = p1 * p2;
	Polynomial p4 = p1 + p2;
	cout << p3 << endl;
	cout << p4 << endl;
	
	return 0;
}
