struct Tree_node {
	int val;
	Tree_node* left_child;
	Tree_node* right_child;
	Tree_node(int);
	Tree_node() {}
};

class Binary_tree {
	private:
		Tree_node* root;
	public:
		Binary_tree(); Binary_tree(int); 
		~Binary_tree();
		bool add(int); 
		void print_pre_order(); void print_in_order(); void print_post_order();
		void print_level_order();
		void print();
		int height(); int sum();
};

