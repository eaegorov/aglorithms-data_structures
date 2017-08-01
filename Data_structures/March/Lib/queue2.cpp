#include <iostream>
#include "queue2.h"
using namespace std;

Queue2::Queue2(int n){
	maxsize = n;
	QueueArr = new int[n];
	bot = 0;
//	top = -1;
	sz = 0;
}

Queue2::~Queue2(){
	delete[] QueueArr;
}

void Queue2::push(int data) {
//	if (top == maxsize - 1)
//		top = -1;
//	top++;
	QueueArr[(bot + sz) % maxsize] = data;
	sz++;
}

void Queue2::pop() {
//	bot++;
//	if (bot == maxsize)
//		bot = 0;
	bot = (bot + 1) % maxsize;	
	sz--;
}

bool Queue2::empty() {
	return !sz;
}

int Queue2::size() {
	return sz;
}

int& Queue2::front() {
	return QueueArr[bot];
}

int& Queue2::back() {
	return QueueArr[(bot + sz - 1) % maxsize];
}

void error_msg(bool check){
	if(!check)
		cout << "Error \n";
}
