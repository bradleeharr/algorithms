#include "pch.h"
#include "linear_search.h"
#include <iostream>

using namespace std;

// Inputs :
// A : Array A
// x : values to search for
int linear_search(int* A, int n, int* x, int k)
{
	cout << "A size: " << n << endl;
	cout << "x size: " << k << endl;
	for (int i = 0; i < n - k + 1; i++) {
		int offset = 0;
		while (offset < k && A[i+offset] == x[offset]) {
			offset = offset + 1;
		} 
		if (offset == k) {
			return i;
		}
	}
	return -1;
}