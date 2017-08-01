#include <iostream>
#include "priority_queue.h"
using namespace std;

Priority_queue::Priority_queue(int n) {
	a = new int[n];
	max_size = n;
	heap_size = 0;
}

Priority_queue::~Priority_queue() {
	delete[] a;
}

void Priority_queue::push(int x) {
	a[heap_size] = x;
	int k = heap_size;
	while (k && a[k] < a[(k - 1) / 2]) {
		swap(a[k], a[(k - 1) / 2]);
		k = (k - 1) / 2;
	}
	heap_size++;
	for (int i = 0; i < heap_size; i++) 
			cout << a[i] << " ";
		cout << endl;
}

void Priority_queue::pop() {
	int min = a[0];
	a[0] = a[heap_size - 1];
	heap_size--;
	int t = heap_size;
	int i = 0;
	while (i * 2 + 2 < t && (a[i * 2 + 1] < a[i] || a[i * 2 + 2] < a[i]))
		if (a[i * 2 + 2] < a[i * 2 + 1]) {
            swap(a[i], a[i * 2 + 2]);
            i = i * 2 + 2;
        }
        else {
            swap(a[i], a[i * 2 + 1]);
            i = i * 2 + 1;
        }
 
    if (i * 2 + 1 < t && a[i * 2 + 1] < a[i]) {
        swap(a[i], a[i * 2 + 1]);
        i = i * 2 + 1;
    }

    for (int i = 0; i < heap_size; i++) 
		cout << a[i] << " ";
	cout << endl;
}

const int& Priority_queue::top() {
	return a[0];
}

int Priority_queue::size() {
	return heap_size;
}

bool Priority_queue::empty() {
	return !heap_size;
}

void error_msg(bool check) {
	if (!check)
		cout << "Error\n";
}
