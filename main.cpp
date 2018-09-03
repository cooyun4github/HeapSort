#include<iostream>
#include "HeapSort.h"
using namespace std;

int main() {
	int test[7] = { 2,1,3,7,4,0,6 };
	Heap heap1(test, sizeof(test));
	for (int i = 0; i < sizeof(test) / sizeof(int); i++) {
		cout << test[i] << " ";
	}
	cout << endl;

	heap1.heap_sort(test, sizeof(test) / sizeof(int));
	for (int i = 0; i < sizeof(test) / sizeof(int); i++) {
		cout << test[i] << " ";
	}
	cout << endl;

	return 0;
}