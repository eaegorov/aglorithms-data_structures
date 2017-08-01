#include "binary_tree.h"
#include <iostream>
#include <queue>

using namespace std;

Tree_node::Tree_node(int d) {
	val = d; 
	left_child = NULL; 
	right_child = NULL;
}

Binary_tree::Binary_tree() {
	root = NULL;
}

Binary_tree::Binary_tree(int data) {
	Tree_node* node = new Tree_node(data);
	root = node;
}

void Delete(Tree_node* r) {
	if (r != NULL){
		Delete(r -> left_child);
		Delete(r -> right_child);
		delete r;
	}
}

Binary_tree::~Binary_tree() {
	Delete(root);
}

bool Binary_tree::add(int data) {
	if (root == NULL) {
		root = new Tree_node(data);
		return true;
	}
	Tree_node* temp = root;
	while(true) { 
		if (temp -> val == data)
			return false;
			
		else if (data < temp -> val)
			if (temp -> left_child == NULL) {
				temp -> left_child = new Tree_node(data);
				return true;
			}
			else
				temp = temp -> left_child;
		
		else if (temp -> right_child == NULL) {
				temp -> right_child = new Tree_node(data);
				return true;
			}
		else 
			temp = temp -> right_child;
	}
}

void print_preorder(Tree_node* r) {
	if (r != NULL) {
		cout << r -> val << " ";
		print_preorder(r -> left_child);
		print_preorder(r -> right_child);
	}
}

void print_inorder(Tree_node* r) {
	if (r != NULL) {
		print_inorder(r -> left_child);
		cout << r -> val << " ";
		print_inorder(r -> right_child);
	}
}

void print_postorder(Tree_node* r) {
	if (r != NULL) {
		print_postorder(r -> left_child);
		print_postorder(r -> right_child);
		cout << r -> val << " ";
	}
}

void Binary_tree::print_pre_order() {
	print_preorder(root);
	cout << endl;
}

void Binary_tree::print_in_order() {
	print_inorder(root);
	cout << endl;
}

void Binary_tree::print_post_order() {
	print_postorder(root);
	cout << endl;
}

void Binary_tree::print_level_order() { 
	queue <Tree_node*> q; 
	q.push(root); 
	while (!q.empty()) { 
		Tree_node* r = q.front(); q.pop(); 
		if(r -> left_child != NULL) 
			q.push(r -> left_child); 
		if(r -> right_child != NULL) 
			q.push(r -> right_child); 
		cout << r -> val << " "; 
	} 
	cout << endl;
}

int height1(Tree_node* r) {
	if (r != NULL)
		return max(height1(r -> left_child), height1(r -> right_child)) + 1;
	else
		return 0;	
}

int Binary_tree::height() {
	return height1(root);
} 

void print1(Tree_node* r, int l) {
    if(r == NULL) {
        for(int i = 0; i < l; i++)
        	cout << "    ";
        cout << "@" << endl;
    }
    else {
        print1(r -> right_child, l + 1);
        for(int i = 0; i < l; i++)
        	cout << "    ";
        cout << r -> val << endl;
        print1(r -> left_child, l + 1);
    }
}

void Binary_tree::print() {
	print1(root, 0);
}

int sum1(Tree_node* r) {
    return r ? sum1(r -> left_child) + sum1(r -> right_child) + r -> val : 0;
}

int Binary_tree::sum() {
	return sum1(root);
}
