#include <iostream>
#include <cstdlib>
#include <ctime>
#include "..\Lib\heap_sort.h"
using namespace std;

int main() {
	int n;
	cin >> n;
	int* a = new int [n];
	
	srand(time(NULL));
	for (int i = 0; i < n; i++)
		a[i] = 1 + rand() % 101;
	
	heap_sort(a, n);
	
	for (int i = 0; i < n; i++)
		cout << a[i] << " ";
	cout << endl;
	
	return 0;
}
