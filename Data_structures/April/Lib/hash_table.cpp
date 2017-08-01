#include "hash_table.h"
#include <iostream>
using namespace std;

int Hash_table::hash(int key) {
	return key % table_size;
}

Hash_table::Hash_table(int size, char* nf){
	table_size = size;
	not_found = nf;
	table = new cell* [table_size];
	for(int i = 0; i < table_size; i++) {
		table[i] = 0;  
	} 
}

Hash_table::~Hash_table() {
	for(int i = 0; i < table_size; i++) {
		cell* temp = table[i];
		while(temp) {
			cell* prev = temp;
			temp = temp -> next;
			delete prev;
		}
	}
	delete[] table;
}

bool Hash_table::add(char* data, int k){
	int h = hash(k);
	cell* p = table[h];
	while(p) {
		if (p -> key == k)
			return 0;
		else p = p -> next;
	}
	if(!p) {
		cell* temp = new cell;
		temp -> data = data;
		temp -> key = k;
		temp -> next = table[h];
		table[h] = temp;
		return true;
	}
}

void Hash_table::remove(int k) {
	int h = hash(k);
	if(table[h] && table[h] -> key == k){
		cell* temp = table[h];
		table[h] = table[h] -> next;
		delete temp;
	}
	else {
		cell* p = table[h];
		cell* temp = table[h];
		while(p && p -> key != k){
			temp = p;
			p = p -> next;
		}
		if(p) {
			temp -> next = p -> next;
			delete p;
		}
	}	
}

char* Hash_table::find(int k) {
	int h = hash(k);
	cell* temp = table[h];
	while(temp && temp -> key != k) 
		temp = temp -> next;
	if(temp) 
		return temp -> data;
	else 
		return not_found;	
}

void Hash_table::print() {
	for(int i = 0; i < table_size; i++) {
		cout << i << ": ";
		cell* temp = table[i];
		while(temp) {
			cout << "[" << temp -> data << ", " << temp -> key << "]";
			temp = temp -> next;
		}
		cout << endl;
	}
}
