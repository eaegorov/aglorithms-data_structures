#include <iostream>
using namespace std;

int main() {
	int n;
	cin >> n;
	int* L = new int[n];
	int* R = new int[n];
	
	for (int i = 0;i < n;i++)
	    cin >> L[i];
	for (int i = 0;i < n;i++)
	    cin >> R[i];
	
	int min = L[0], max = R[0];
	for(int i = 0;i < n;i++){
		if (L[i] < min) 
	    	min = L[i];
		if (R[i] > max) 
	        max = R[i];
	}
	
	int max_count = 0;
	while (min < max){
		int i = 0, t = 0;
	    while (i < n){
		    if ((min >= L[i]) and (min <= R[i])) 
		        t++; 
		    if (t > max_count) 
		        max_count = t;
		    i++;
        }
        min++;
	}
	
	cout << max_count;
	
	delete[] L;
	delete[] R;
	return 0;
}
