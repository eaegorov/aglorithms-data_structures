#include <cstdlib>
#include <iostream>

using namespace std;

bool rec_func(int* A,int n, int k, bool* B, int inc, int exc){
	if(k == n && inc == 0)
		return true;
	else if(k < n && inc >= 0&& exc >= 0){
			bool b;
			B[k] = true;
			b = rec_func(A, n, k + 1, B, inc - A[k], exc);
			if(b) 
				return true;
			else{
				B[k]=false;
				return rec_func(A,n,k+1,B,inc,exc-A[k]);
			}
		}
	return false;
}

bool subset_enumeration(int*A,int n,bool*B,int S){
	int sum=A[0];
	for(int i=1; i<n; i++)
		sum+=A[i];
	return rec_func(A,n,0,B,S,sum-S);
}

int main(int argc, char** argv) {
	int n;
	cin>>n;
	int A[n];
	bool B[n];
	int S;
	cin>>S;
	for(int i=0; i<n; i++)
			cin>>A[i];
	if(subset_enumeration(A,n,B,S)){
		for(int i=0; i<n; i++)
			if(B[i])
				cout << A[i] << " ";
	}
	else 
		cout<<"No";
    return 0;
}
