#include <iostream>
#include "../Lib/single_list.h"
using namespace std;

template <class Value, class ForwardIterator>
void merge(ForwardIterator first, ForwardIterator last, Value* buffer) {
	ForwardIterator mid = first + (last - first) / 2; 
	ForwardIterator f = first;
	ForwardIterator m = mid;
	
	Value* b = buffer;

    while (f != mid && m != last)
        if (*f < *m) {
            *buffer++ = *f++;
        }

        else {
            *buffer++ = *m++;
        }

    while (f != mid) {
        *buffer++ = *f++;
    }

    while (m != last) {
        *buffer++ = *m++;
    }
    
    while (first != last) {
        *first++ = *b++;
    }
}


template <class Value, class ForwardIterator>
void merge_helper(ForwardIterator first, ForwardIterator last, Value* buffer) {
    if (last - first > 1) {
        ForwardIterator mid = first + (last - first) / 2;
        merge_helper(first, mid, buffer);
        merge_helper(mid, last, buffer);
        merge(first, last, buffer);
    }
}

template <class Value, class ForwardIterator>
void mergeSort(ForwardIterator first, ForwardIterator last) {
	Value* buffer = new Value[last - first];
	
	merge_helper(first, last, buffer);

	delete [] buffer;
}

int main() {
	single_list l1;
	l1.push_front(5);
	l1.push_front(7);
	l1.push_front(1);
	l1.push_front(12);
	l1.push_front(3);
	l1.print();

	mergeSort <int> (l1.begin(), l1.end());
	
	l1.print();
	return 0;
}
