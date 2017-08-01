#include <iostream>
#include "..\Lib\queue1.h"
using namespace std;

int main() {
	Queue Q;
	Q.push(8); Q.push(7); Q.push(6); Q.push(2);
	error_msg(Q.size() == 4); error_msg(Q.back() == 2);
	error_msg(Q.front() == 8);
	Q.pop(); error_msg(Q.front() == 7);
	Q.pop(); error_msg(Q.front() == 6);
	Q.pop(); error_msg(Q.front() == 2);
	Q.pop(); error_msg(Q.empty());
	
	return 0;
}
