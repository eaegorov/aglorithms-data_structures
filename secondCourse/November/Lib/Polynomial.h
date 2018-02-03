#include <iostream>
using namespace std;

class Polynomial {
	int number; 
	int* coefficients;
	public:
		Polynomial(); Polynomial(int, int);
		Polynomial(int n, const int*);
		Polynomial(const Polynomial&);
		~Polynomial();
		int degree();
		int operator [](int);
		int operator ()(int);
		Polynomial operator + (const Polynomial&);
		Polynomial& operator += (const Polynomial&);
		Polynomial operator * (const Polynomial&);
		Polynomial operator *= (const Polynomial&);
		Polynomial& operator = (const Polynomial&);
		bool operator == (const Polynomial&);
		bool operator != (const Polynomial&);
		Polynomial operator * (int);
		Polynomial operator *= (int);
		
		friend Polynomial operator * (int x, const Polynomial& pol) {
			return x * pol;
		}

		friend ostream& operator << (ostream& pout, const Polynomial& pol) {
			for(int i = pol.number - 1; i >= 0; i--) {
			    if(pol.coefficients[i] != 0)
			    	if(i == 0)
			    		cout << "(" << pol.coefficients[i] << ")";
			    	else if(i == 1)
			    		cout << "(" << pol.coefficients[i] << ")*x+";
			    	else cout << "(" << pol.coefficients[i] << ")*x^" << i << "+";
			}
			return pout;
		}
};
