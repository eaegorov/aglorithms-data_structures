struct cell {
	char* data;
	int key;
	cell* next;
};

class Hash_table {
	private:
		cell** table;
		int table_size;
		char* not_found;
		int hash(int);
	public:
		Hash_table(int size, char* not_found);
		~Hash_table();
		bool add(char* data, int key);
		void remove(int);
		char* find(int);
		void print();
};
