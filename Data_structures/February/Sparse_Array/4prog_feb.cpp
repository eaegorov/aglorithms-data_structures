#include <iostream>
using namespace std;

struct cell{
    int col;
    cell* right;
    int data;      
};

class Sparse_Array{
private:
    cell* head;
    int default_value;
public:
    Sparse_Array(int); ~Sparse_Array();
    int& operator[](int);
    void print();         
};

Sparse_Array::Sparse_Array(int number){
    default_value = number;
    head = new cell;
    head -> right = NULL;
    head -> col = -1;
}
Sparse_Array::~Sparse_Array(){
    cell* temp = head -> right;
    while(temp){
        delete head;
        head = temp;
        temp = head -> right;    
    }
    delete head;                          
}
int& Sparse_Array::operator[](int x){
    cell* temp1 = head;
    cell* temp2 = head -> right;
    
    while (temp2 != NULL && temp2 -> col < x) {
        temp1 = temp2;
        temp2 = temp2 -> right;
    }
    if (temp2 != NULL && temp2 -> col == x)
    	return temp2 -> data;
    else {	
        cell* newcell = new cell;
        newcell -> col = x;
        newcell -> data = default_value;
        temp1 -> right = newcell;
        newcell -> right = temp2;
        return newcell -> data;
    }     
}
void Sparse_Array::print(){
    cell* temp = head -> right;
    
    while(temp){
        cout << "[" << temp -> col << ", " << temp -> data << "] ";
        temp = temp -> right;    
    }  
    cout << endl; 
}

int main() {
	Sparse_Array A(-1);
	A[8] = 5;
	cout << A[89] << endl;
	A[1000] = A[8] + A[56];
	A[9] = 0;

	A.print();
		
	return 0;
}
