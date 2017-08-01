class Priority_queue {
	private:
		int* a;
		int max_size;
		int heap_size;
	public:
		Priority_queue(int); ~Priority_queue();
		void push(int); void pop();
		const int& top(); int size();
		bool empty();
};

void error_msg(bool check);
