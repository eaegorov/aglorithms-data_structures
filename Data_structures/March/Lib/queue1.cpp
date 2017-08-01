#include <iostream>
#include "queue1.h"
using namespace std;

Queue::Queue() {}

Queue::~Queue() {}

bool Queue::empty(){
	return Q.empty();
}

void Queue::push(int data){
	Q.push_front(data);
}

void Queue::pop(){
	Q.pop_back();
}

int Queue::size(){
	return Q.size();
}

int& Queue::back(){
	return Q.front();
}

int& Queue::front(){
	return Q.back();;
}

void error_msg(bool check){
	if(!check)
		cout << "Error \n";
}
