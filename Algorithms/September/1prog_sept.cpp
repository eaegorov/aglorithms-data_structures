#include <iostream>
#include <cmath>

using namespace std;

int main() {
	int n;
	double x, eps, e_x, res, step, fact;
	
	cin >> x >> eps;
	n = 1;
	res = x;
	step = x;
	fact = n;
	e_x = 1;
	
	while (res > eps || res < -eps){
		e_x = e_x + res;
		n++;
		step *= x;
		fact *= n;
		res = step / fact;
	}

    cout << e_x << endl;
    
	return 0;
}
