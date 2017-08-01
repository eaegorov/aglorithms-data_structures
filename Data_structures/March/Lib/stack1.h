#include <iostream>
#include "slist.h"

void error_msg(bool check);

class Stack {
	private:
		single_list S;
	public:
		Stack();
		~Stack();
		bool empty();
	    void push(int); void pop();
	    int size();
	    int& top();
};
