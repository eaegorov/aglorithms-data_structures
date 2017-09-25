#include <iostream>
using namespace std;

struct single_node{
	int val;
	single_node* next;
	single_node(int a, single_node* b){
		val = a;
		next = b;
	}
	single_node(){}
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
		single_list(const single_list&);
		single_list& operator = (const single_list&);
		bool empty();
	    void push_front(int); void pop_front();
	    int size();
	    void clear();
	    int& front();
	    void print();
};
