#include <algorithm>
#include <iostream>
using namespace std;

void func(int* a, int n){
	int i = 0, count = 0; 
	while (i < n - 1){
	    if ((a[i] % 2 == 1) && (a[i + 1] % 2 == 0))
	        swap(a[i], a[i + 1]), count++;
	    i++;
	}
	if (count != 0) func(a, n);
}

int main() {
	int n;
	cin >> n;
    int* a = new int[n];
    
    for (int i = 0;i < n;i++)
    	cin >> a[i];
    	
    func(a, n);
    
    for (int i = 0;i < n;i++)
        cout << a[i] << " ";
        
    return 0;
}
