#include <iostream>
#include <string>
using namespace std;

char lower(char s){
	char r = 'A' - 'a';
	if (s <= 'Z' && s >= 'A')
		return s - r;
}

int strcmpi(char* s1, char* s2){
	int i;
	for(i = 0;s1[i] && lower(s1[i]) == lower(s2[i]);i++)
		;
	return lower(s1[i]) - lower(s2[i]);
}

int main(){
	int size1, size2;
	cin >> size1 >> size2;
	char s1[size1];
	char s2[size2];
	
	cin >> s1;
	cin >> s2;
	
 	cout << strcmpi(s1, s2);
    return 0;
}
