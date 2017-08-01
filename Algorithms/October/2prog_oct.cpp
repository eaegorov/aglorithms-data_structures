#include<iostream>
using namespace std;

int main() {
	int n, m;
	cin >> n >> m;
	int M[n][m];
	
	for (int i=0; i < n; i++)
	    for (int j=0; j < m; j++)
	        cin >> M[i][j];
	
	int i = 1;
	int x = 0, j = 0;
	int t;
	int B[n-1];
	bool k = false;
	
	for (int i = 0; i < n-1; i++)
	    B[i] = 0;
	while (x < m) {
	    t = M[0][x];
	    while (i < n) {
	        k = false;
	        j = B[i-1];	
	        while(M[i][j] < t) 
	            j++;
	        if (t == M[i][j])
	            k = true;
            B[i-1] = j;
            if (k)  
                i++;
            else break;
    }
    if (k)
        break;
    else {
        x++;
        i = 1;
    }
 }
	cout << t;
    return 0;
}
