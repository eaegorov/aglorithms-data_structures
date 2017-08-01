#include "dlist.h"
class Queue{
	private:
		double_list Q;
	public:
		Queue();
	    ~Queue();
		void push(int); void pop();
		bool empty(); int size();
		int& front(); int& back();
};

void error_msg(bool check);
