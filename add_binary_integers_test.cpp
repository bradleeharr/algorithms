#include "gtest/gtest.h"
#include <iostream>
#include "pch.h"
#include "add_binary_integers.h"

using namespace std;

TEST(AddBinaryIntegers, BinaryIntegersTest) {
	int array_size = 31; // 31-bit max. If you add two 32 bit numbers, you will get overflows 
	int* A = new int[array_size]; 
	int* B = new int[array_size]; 
	srand(time(NULL));
	// Test for 20 random binary integers
	for (int i = 0; i < 20; i++) {
		cout << "A     | B" << endl;
		for (int i = 0; i < array_size; i++) {
			A[i] = rand() % 2;
			B[i] = rand() % 2;
			cout << A[i] << "     | " << B[i] << " | " << endl;
		}
		int* C = add_binary_integers(A, B, array_size);

		// Convert Binary to Decimal and Compare
		int a = 0;
		int b = 0;
		int c = 0;
		for (int i = 0; i < array_size; i++) {
			a += A[i] << i;
			b += B[i] << i;
			c += C[i] << i;
		}
		c += C[array_size] << array_size;
		cout << "a:" << a << " ";
		cout << "b:" << b << " ";
		cout << "c:" << c << endl;
		EXPECT_EQ(a + b, c);
	}
}