#include <iostream>
#include "stack1.h"
using namespace std;

Stack::Stack(){}

Stack::~Stack(){}

bool Stack::empty(){
	return S.empty();
}

void Stack::push(int data){
	S.push_front(data);
}

void Stack::pop(){
	S.pop_front();
}

int Stack::size(){
	return S.size();
}

int& Stack::top(){
	return S.front();
}

void error_msg(bool check){
	if(!check)
		cout << "Error \n";
}
