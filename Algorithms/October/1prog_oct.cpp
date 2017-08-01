#include <iostream>

using namespace std;

int main() {
	int n, m;
	cin >> n >> m;
	int A[n];
	int B[m];
	int k = 0;
	
	for (int i = 0; i < n; i++)
        cin >> A[i];              
    for (int i = 0; i < m; i++)
        cin >> B[i];
    
    int i = 0, j = 0;
    while (i != n && j != m)
    {
    	if (A[i] == B[j])
    	{
    	    i++;
    	    j++;
    	    k++;
    	}
    	else 
    	    i++;
    }
	
	if (k == m)
	    cout << "Yes";
	else 
	    cout << "No";	
	return 0;
}
