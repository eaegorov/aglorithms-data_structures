#include <iostream>
#include "..\Lib\priority_queue.h"
using namespace std;

int main() {
	Priority_queue Q(10);
	Q.push(4); Q.push(2); Q.push(6); Q.push(8); Q.push(1); Q.push(3);
	Q.pop(); Q.pop(); Q.pop(); Q.pop(); Q.pop(); Q.pop();
/*	Q.push(1); Q.push(4); Q.push(2); Q.push(8);
	error_msg(Q.size() == 4);
	error_msg(Q.top() == 1);
	Q.pop(); error_msg(Q.top() == 2);
	Q.pop(); error_msg(Q.top() == 4);
	Q.pop(); error_msg(Q.top() == 8);
	Q.pop(); error_msg(Q.empty());
*/	
	return 0;
}
