#include "..\Lib\binary_tree.h"
#include <iostream>
using namespace std;

int main() {
	Binary_tree T(5);
	T.add(3);
	T.add(1);
	T.add(2);
	T.add(4);
	T.add(9);
	T.add(7);
	T.add(6);
	T.add(12);
	T.add(8);
	T.print_in_order();
	T.print_pre_order();
	T.print_post_order();
	T.print_level_order();
	cout << T.height() << endl;
//	T.print();
	cout << T.sum();
	
	return 0;
}
