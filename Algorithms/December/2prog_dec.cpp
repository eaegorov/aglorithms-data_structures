#include <iostream>
using namespace std;

int main() {
	int n;
	cin >> n;
	int* a = new int[n];
	
	for (int i = 0;i < n;i++)
    	cin >> a[i];
    	
    int sum = a[0];
	int maxsum = a[0];
	for (int i = 1;i < n;i++){
		if (sum < 0)
		    sum = 0;
		sum += a[i];
		if (sum > maxsum)
			maxsum = sum;
	}

	cout << maxsum;
	delete[] a;
	return 0;
}
