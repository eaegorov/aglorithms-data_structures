
#include <cstdlib>
#include <iostream>


using namespace std;



int binarysearch(int* t, int r, int p){
    int l = 0;
    while(l <= r){
        int m = (l + r) / 2;
        if(p > t[m])
            l = m + 1;
        else
            r = m - 1;
    }
    if(p > t[l]) 
		l++;
    return l;
}

int main()
{
    int n;
    cin >> n;
    int* a = new int[n];
    
    for(int i = 0;i < n;i++)
    	cin >> a[i];

    int* sub = new int[n];
    sub[0] = a[0];

    int max = 1;
    for(int i = 1;i < n;i++){
        if(a[i]> sub[max - 1]){
        	sub[max] = a[i];
        	max++;
        }
        else
          sub[binarysearch(sub, max, a[i])] = a[i];
    } 

    cout << max;
    return 0;
}

