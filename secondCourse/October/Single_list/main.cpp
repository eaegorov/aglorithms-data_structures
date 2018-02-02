#include <iostream>
#include "../Lib/single_list.h"
using namespace std;


int main() {
	single_list l;
	for (int i = 0; i < 6; i++) {
		l.push_front(i);
	}
	for (single_list::iterator i = l.begin(); i != l.end(); i++)
		cout << *i << " ";
	cout << endl;

	return 0;
}
