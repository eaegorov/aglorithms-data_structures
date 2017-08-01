class Queue2 {
	private:
		int* QueueArr;
		int bot;
		//int top;
		int sz;
		int maxsize;
	public:
		Queue2(int n);
		~Queue2();
	    void push(int); void pop();
	    bool empty(); int size();
	    int& front(); int& back();
};

void error_msg(bool check);
