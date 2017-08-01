#include <iostream>
using namespace std;

struct single_node{
	int val;
	single_node* next;
};

class single_list{
	private:
		single_node* head;
		single_node* tail;
	public:
		single_list(){
			tail = new single_node;
			head = tail;
		}
		single_list(int); ~single_list();
		bool empty();
	    void push_front(int); void pop_front();
	    int size();
	    void clear();
	    int& front();
	    void print();
};

single_list::single_list(int data){
	tail = new single_node;
	single_node* elem = new single_node;
	elem -> next = tail;
	elem -> val = data;
	head = elem;
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
	single_node* newlink = new single_node;
	newlink -> val = data;
	newlink -> next = head;
	head = newlink;
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

int main(){
	single_list list(5);
	list.push_front(13);
	list.push_front(4);
	list.push_front(8);
	list.print();
	int s = list.size();
	cout << s << endl;
	list.pop_front();
	list.front() = 1;
	list.print();
	list.pop_front();
	list.print();
	bool b = list.empty();
	cout << b << endl;
	list.clear();
	list.print();
	
	return 0;
}
