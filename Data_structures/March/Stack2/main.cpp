#include <iostream>
#include "..\Lib\stack2.h"
using namespace std;

int main() {
	Stack2 S(3);
	S.push(8); S.push(7); S.push(4);
	error_msg(S.size() == 3);
	error_msg(S.top() == 4);
	S.pop(); error_msg(S.top() == 7);
	S.pop(); error_msg(S.top() == 8);
	S.top() = 2;
	error_msg(S.top() == 2); S.pop();
	error_msg(S.empty());
	
	return 0;
}
