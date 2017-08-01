#include <iostream>
#include "dlist.h"
using namespace std;

double_node::double_node(int v, double_node* n, double_node* p){
	val = v;
	next = n;
	prev = p;
}

double_list::double_list(){
	tail = new double_node;
	tail -> next = tail;
	tail -> prev = tail;
	sz = 0;
}

double_list::double_list(int data){
	tail = new double_node;
	double_node* elem = new double_node(data, tail, tail);
	sz++;
	tail -> next = elem;
	tail -> prev = elem;
}

double_list::~double_list(){
	double_node* temp = tail -> next;
	while (temp != tail){
		temp = temp -> next;
		delete temp -> prev;
	}
	delete tail;
}

bool double_list::empty(){
	return sz == 0;
}

void double_list::push_front(int data){
	double_node* newlink = new double_node(data, tail -> next, tail);
	sz++;
	tail -> next -> prev = newlink;
	tail -> next = newlink;
}

void double_list::pop_front(){
	double_node* temp = tail -> next -> next;
	temp -> prev = tail;
	delete tail -> next;
	tail -> next = temp;
	sz--;
}

void double_list::push_back(int data){
	double_node* newlink = new double_node(data, tail, tail -> prev);
	sz++;
	tail -> prev -> next = newlink;
	tail -> prev = newlink;
}

void double_list::pop_back(){
	double_node* temp = tail -> prev -> prev;
	temp -> next = tail;
	delete tail -> prev;
	tail -> prev = temp;
	sz--;
}

int double_list::size(){
	return sz;
}

void double_list::clear(){
	double_node* temp = tail -> next;
	while (temp != tail){
		tail -> next = temp -> next;
		delete temp;
		temp = tail -> next;
	}
	temp -> prev = tail;
	sz = 0;
}

int& double_list::back(){
	return tail -> prev -> val;
}

int& double_list::front(){
	return tail -> next -> val;
}

void double_list::print(){
	double_node* current = tail -> next;
	while (current != tail){
		cout << current -> val << " ";
		current = current -> next;
	}
	cout << endl;
}
