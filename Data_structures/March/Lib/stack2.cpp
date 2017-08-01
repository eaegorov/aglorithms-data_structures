#include <iostream>
#include "stack2.h"
using namespace std;

Stack2::~Stack2(){
	delete[] StackArr;
}

void Stack2::push(int data) {
	StackArr[peek] = data;
    peek++;
}

void Stack2::pop() {
	//if (peek >= 0) 
	peek--;
}

bool Stack2::empty() {
	return !peek;
}

int Stack2::size() {
	return peek;
}

int& Stack2::top() {
	return StackArr[peek - 1];
}

void error_msg(bool check){
	if(!check)
		cout << "Error \n";
}
