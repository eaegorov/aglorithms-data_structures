#include <iostream>
using namespace std;

int main(){
	int n, x;
	cin >> n >> x;
	
	int* A = new int[n];
	bool* B = new bool[n];

	for(int i = 0;i < n;i++)
		cin >> A[i];
		
	for(int i = 0;i < n;i++)
		B[i] = false;
		
	bool b = true;
	while(b){
		int sum = 0;
		for(int i = 0;i < n;i++)
			if(B[i] == true)
				sum += A[i];
		if(sum == x){
			for(int i = 0;i < n;i++)
				if(B[i] == true)
					cout << A[i] << " ";
			b = false;
			break;
		}
		int j = n - 1;
		while(j >= 0 && B[j] == true)
			j--;
		if (j >= 0){
			B[j] = true;
			for(int i = 1 + j;i < n;i++)
				B[i] = false;
		}
		else {
			b = false;
			cout << "NO!";
		}
	}
	delete[] A;
	delete[] B;
    return 0;
}
