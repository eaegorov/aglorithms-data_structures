#include <iostream>
using namespace std;

int binary_search(int* arr, int right, int x){
    int left = 0;
    while (left < right){
        int mid = (left + right) / 2;
        if (x > arr[mid])
            left = mid + 1;
        else
            right = mid - 1;
    }
    if (x > arr[left])
		left++;
    return left;
}

int main(){
    int n;
    cin >> n;
    int* a = new int[n];
    
    for(int i = 0;i < n;i++)
    	cin >> a[i];

    int* b = new int[n];
    b[0] = a[0];

    int max = 1;
    for (int i = 1;i < n;i++){
        if (a[i] > b[max - 1]){
        	b[max] = a[i];
        	max++;
        }
        else
          b[binary_search(b, max, a[i])] = a[i];
    } 
    cout << max;
    return 0;
}

