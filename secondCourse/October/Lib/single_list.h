#include <iostream>
using namespace std;

class single_list {
	private:
		struct single_node {
			int val;
			single_node* next;
			single_node(int a, single_node* b) {
				val = a;
				next = b;
			}
			single_node(){}
		};
		single_node* head;
		single_node* tail;
	public:
		single_list() {
			head = tail = new single_node;
		}
		
		single_list(int data) {
			tail = new single_node;
			head = new single_node(data, tail);
		} 
		
		~single_list() {
			while (head != tail) {
				single_node* temp = head -> next;
				delete head;
				head = temp;
			}
			delete head;
		}
		
		single_list(const single_list& list) {
			head = tail = new single_node();
			if (!empty()) {
				single_node* current = list.head;
				if (current != list.tail) {
					head = new single_node(current -> val, head);
				}
				single_node* temp = list.head->next;
				while (temp != list.tail) {
					single_node* tmp = new single_node(temp->val, tail);
					current->next = tmp;
					current = current->next;
					temp = temp->next;
				}
				current->next = tail;
			}
		}
		
		single_list& operator = (const single_list& list) {
			if (!empty())
				clear();
			head = tail = new single_node();
			single_node* current = list.head;
			if (current != list.tail) {
				head = new single_node(current -> val, head);
			}
			single_node* temp = list.head->next;
			while (temp != list.tail) {
				single_node* tmp = new single_node(temp->val, tail);
				current->next = tmp;
				current = current -> next;
				temp = temp -> next;
			}
			current -> next = tail;
			return *this;
		}
		
		bool empty() {
			return head == tail;
		}
		
	    void push_front(int data) {
	    	single_node* newlink = head;
			head = new single_node(data, newlink);
		}
		
		void pop_front() {
			single_node* temp = head -> next;
			delete head;
			head = temp;
		}
		
	    int size() {
	    	single_node* sub = head;
			int k = 0;
			while (sub != tail) {
				sub = sub -> next;
				k++;
			}
			return k;
		}
		
	    void clear() {
	    	single_node* sub = head;
			while (sub != tail) {
				sub = head -> next;
				delete head;
				head = sub;
			}
		}
		
	    int front() {
	    	return head -> val;
		}
		
	    void print() {
	    	single_node* current = head;
			while(current != tail) {
				cout << current -> val << " ";
				current = current -> next;
			}
			cout << endl;
		}
	    class iterator {
	    	private:
	    		single_node* pointer;
	    	public:
	    		iterator (single_node* p) {
                   pointer = p;
                }
                
	    		int& operator * () {
                    return pointer -> val;
                }
                
                iterator operator ++ () {
                    pointer = pointer -> next;
                    return iterator(pointer);
                }
                
                iterator operator ++ (int) {
                    single_node* prev = pointer;
                    pointer = pointer -> next;
                    return iterator(prev);
                }
                
                iterator operator + (int n) {
                       single_node* t = pointer;
                       for (int i = 0; i < n; i++)
                       		t = t -> next;
                       return iterator(t);
                }
                
                bool operator == (iterator q) {
                    return pointer == q.pointer;
                }
                
                bool operator != (iterator q) {
                    return pointer != q.pointer;
                }
                
                int operator - (iterator q) {
                    int k = 0;
                    iterator p = q;
                    for (k = 0; p != *this; k++)
                    	p++;
                    return k;
              }
		};
		iterator begin() {
			return iterator(head);
		}
		iterator end() {
			return iterator(tail);
		}
};
