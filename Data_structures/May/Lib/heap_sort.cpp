#include <iostream>
#include "heap_sort.h"
using namespace std;
void swap(int* a, int i, int j) {
	int temp = a[i];
	a[i] = a[j];
	a[j] = temp;
}

void max_heap_helper(int* a, int n, int i) {
	while (i < n / 2) {
		int t = 2 * i + 1;
		if (2 * i + 2 < n && a[2 * i + 1] < a[2 * i + 2])
			t = 2 * i + 2;
			if (a[t] > a[i]){
				swap(a, t, i);
				i = t;
			}
		else break;
	}
}

void max_heap (int* a, int n) {
	for (int i = n / 2 - 1; i >= 0; i--)
        max_heap_helper(a, n, i);
}

void heap_sort(int* a, int n) {
	max_heap(a, n);
	for (int size = n - 1; size > 0; size --) {
		swap(a, 0, size);
		max_heap_helper(a, size, 0);
	}
}
