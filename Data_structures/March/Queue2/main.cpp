#include <iostream>
#include "..\Lib\queue2.h"
using namespace std;

int main() {
	Queue2 Q(4);
	Q.push(8); Q.push(7); Q.push(6); Q.push(2);
/*	Q.pop(); Q.pop();
	Q.push(10);
	cout << Q.front() << endl;
	cout << Q.back() << endl;
*/	
	error_msg(Q.size() == 4); error_msg(Q.back() == 2);
	error_msg(Q.front() == 8);
	Q.pop(); error_msg(Q.front() == 7);
	Q.pop(); error_msg(Q.front() == 6);
	Q.pop(); error_msg(Q.front() == 2);
	Q.pop(); error_msg(Q.empty());

	return 0;
}

