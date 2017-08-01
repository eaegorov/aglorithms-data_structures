struct double_node{
	double_node* next;
	double_node* prev;
	int val;
	double_node(int, double_node*, double_node*);
	double_node(){}
};

class double_list{
	private:
		double_node* tail;
		int sz;
	public:
		double_list();
		double_list(int); ~double_list();
		bool empty();
		void push_front(int); void pop_front();
		void push_back(int); void pop_back();
		int size();
		void clear();
		int& front(); int& back();
		void print();
};
