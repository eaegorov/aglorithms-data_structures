#include <iostream>

using namespace std;

int main() {
	int n;
	cin >> n;
	int A[n];
	int res = 0;
	
	for (int i = 0; i < n; i++)
	    cin >> A[i];
	
	for (int i = 0; i < n-1; i++)
	    if (A[i] == 1 && A[i+1] == 0)
	       res++;
	if (A[n-1] == 1)
	    res++;
	    
    cout << res << endl;
	return 0;
}
