#include <algorithm>
#include <iostream>
using namespace std;

void qs_helper(int* a, int l, int r){
	if (r > l){
		int m = (l + r) / 2;
		if (a[l] < a[m])
		    if (a[m] < a[r])
		        swap(a[l], a[m]);
		    else if (a[l] < a[r])
			    swap(a[l], a[r]);
		else if (a[r] < a[m])
		    swap(a[m], a[l]);
		else if (a[r] < a[l])
			swap(a[r], a[l]); 
		int i = l, j = l + 1, k = r, pe = a[l];
		while (j <= k)
		    if (a[j] == pe)
		        j++;
		    else if (a[j] < pe){
		    	swap(a[i], a[j]);
		    	i++;
		    	j++;
		    }
		    else {
		    	swap(a[j], a[k]);
		    	k--;
		    }
		qs_helper(a, l, i - 1), qs_helper(a, k + 1, r);
	}
}

void quick_sort(int* a, int n){
	qs_helper(a, 0, n-1);
}


int main() {
	int n, x;
	cin >> n >> x;
    int* a = new int[n];
    
    for (int i = 0;i < n;i++)
    	cin >> a[i];
    	
    quick_sort(a, n);
    
    int i = 0, j = n - 1;
    int k;
    while (i < j){
    	if (a[i] + a[j] > x)
    	    j--;
    	else if (a[i] + a[j] < x)
    	    i++;
    	else i++, j--, k++;
    }
        cout << k;  
    delete[] a;
    return 0;
}
