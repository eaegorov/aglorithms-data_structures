#include <iostream>
#include "../Lib/single_list.h"

using namespace std;

int main() {
	single_list l1;
	for (int i = 1; i <= 5; i++)
		l1.push_front(i);
	single_list l2 = single_list(l1);
	l2.print();
	single_list l3 = l1;
	l3.print();
	return 0;
}
