#include <iostream>
#include "single_list.h"

using namespace std;

single_list::single_list(int data){
	tail = new single_node;
	head = new single_node(data, tail);
}

single_list::~single_list(){
	while (head != tail){
		single_node* temp = head -> next;
		delete head;
		head = temp;
	}
	delete head;
}

bool single_list::empty(){
	return head == tail;
}

void single_list::push_front(int data){
	single_node* newlink = head;
	head = new single_node(data, newlink);
}

void single_list::pop_front(){
	single_node* temp = head -> next;
	delete head;
	head = temp;
}

int single_list::size(){
	single_node* sub = head;
	int k = 0;
	while (sub != tail){
		sub = sub -> next;
		k++;
	}
	return k;
}

void single_list::clear(){
	single_node* sub = head;
	while (sub != tail){
		sub = head -> next;
		delete head;
		head = sub;
	}
}
int& single_list::front(){
	return head -> val;
}

void single_list::print(){
	single_node* current = head;
	while(current != tail){
		cout << current -> val << " ";
		current = current -> next;
	}
	cout << endl;
}

single_list::single_list(const single_list& list) {
	tail = new single_node;
	head = new single_node(list.head->val, tail);
	single_node* current = head;
	single_node* temp = list.head->next;
	while (temp != list.tail) {
		single_node* tmp = new single_node(temp->val, tail);
		current->next = tmp;
		current = current->next;
		temp = temp->next;
	}
	current->next = tail;
}

single_list& single_list::operator = (const single_list& list) {
	if (!empty())
		clear();
	tail = new single_node;
	head = new single_node(list.head->val, tail);
	single_node* current = head;
	single_node* temp = list.head->next;
	while (temp != list.tail) {
		single_node* tmp = new single_node(temp->val, tail);
		current->next = tmp;
		current = current -> next;
		temp = temp -> next;
	}
	current -> next = tail;
	return *this;
} 
