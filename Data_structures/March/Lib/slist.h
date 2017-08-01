struct single_node{
	int val;
	single_node* next;
	single_node(int, single_node*);
	single_node(){}
};


class single_list{
	private:
		single_node* head;
		single_node* tail;
	public:
		single_list();
		single_list(int); ~single_list();
		bool empty();
	    void push_front(int); void pop_front();
	    int size();
	    void clear();
	    int& front();
	    void print();
};
