#include <iostream>
using namespace std; 

int main(){ 
	int n; 
	cin >> n; 
	int* a = new int[n];
	
	for (int i = 0;i < n;i++) 
		cin >> a[i]; 
		
	int* b = new int[n]; 
	b[0] = 1; 
	
	int maxb = 1; 
	for (int i = 1;i < n;i++){ 
		int max = 0; 
		for (int j = 0;j < i;j++) 
			if (a[j] < a[i] && b[j] > max) 
				max = b[j]; 
		b[i] = max + 1; 
		if (b[i] > maxb) 
			maxb = b[i]; 
	} 
	cout << maxb;
    return 0;
}
