#include <iostream>
using namespace std;

struct double_node{
	double_node* next;
	double_node* prev;
	int val;
	double_node(int v, double_node* n, double_node* p){
		val = v;
		next = n;
		prev = p;
	}
	double_node(){}
};

class double_list{
	private:
		double_node* tail;
		int sz;
	public:
		double_list(){
			tail = new double_node;
			tail -> next = tail;
			tail -> prev = tail;
			sz = 0;
		}
		double_list(int); ~double_list();
		bool empty();
		void push_front(int); void pop_front();
		void push_back(int); void pop_back();
		int size();
		void clear();
		int& front(); int& back();
		void print();
};

double_list::double_list(int data){
	tail = new double_node;
	double_node* elem = new double_node(data, tail, tail);
	sz++;
	/*elem -> val = data;
	elem -> next = tail;
	elem -> tail = prev;*/
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
	/*newlink -> val = data;
	newlink -> next = tail -> next;
	newlink -> prev = tail;*/
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
	/*newlink -> val = data;
	newlink -> next = tail;
	newlink -> prev = tail -> prev;*/
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


int main(){
	double_list mylist;

	mylist.push_front(1);
	mylist.push_back(13);	
	mylist.front() = 2;
	mylist.back() = 14;
	mylist.push_front(11);
	mylist.print();
	mylist.pop_front();
	mylist.pop_back();
	mylist.print();
	
	int c = mylist.size();
//	cout << c << endl;
    bool a = mylist.empty();
//  cout << a << endl;
//  mylist.clear();
//  mylist.print();
	return 0;
}
