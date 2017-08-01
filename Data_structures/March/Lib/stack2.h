class Stack2 {
	private:
		int* StackArr;
		int peek;
	public:
		Stack2(int n){
			StackArr = new int[n];
			peek = 0; 
		}
		~Stack2();
	    void push(int); void pop();
	    bool empty(); int size();
	    int& top();
};

void error_msg(bool check);
