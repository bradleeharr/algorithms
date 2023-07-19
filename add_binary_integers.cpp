#include "pch.h"
#include "add_binary_integers.h"

// A - Binary Number 1
// B - Binary Number 2 
// n = Length in bits
int* add_binary_integers(int* A, int* B, int n)
{
	int* C = new int[n + 1];
	int carry = 0;
	for (int i = 0; i < n; i++) {
		C[i] = (A[i] + B[i] + carry) % 2; 
		carry = (A[i] + B[i] + carry) > 1;
	}
	C[n] = carry;
	return C;
}