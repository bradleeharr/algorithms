#include "pch.h"
#include "insertion_sort.h"
#include <chrono> 
using namespace std;

// Test to make sure that an arbitrary sorting works correctly
TEST(InsertionSort, TestArbitrarySort) {
	int A[] = { 1,3,5,7,9,10,8,6,4,2,0 };
	int A_expected[] = { 0,1,2,3,4,5,6,7,8,9,10 };
	int n = sizeof(A) / sizeof(A[0]);
	insertion_sort(A, n);
	for (int i = 0; i < n; i++) {
		EXPECT_EQ(A[i], A_expected[i]);
	}
}

// Test to make sure that if n < maxsize, it will correctly 
// keep the last couple elements unchanged 
// Showing that it is performing insertion sort
TEST(InsertionSort, TestPartialSort) {
	int A[] = { 4,4,4,4,1,1,2,3,4,0,0,0,0,0};
	int A_expected[] = {0,0,0,1,1,2,3,4,4,4,4,4,0,0};
	int n = sizeof(A) / sizeof(A[0]);
	insertion_sort(A, n-2);
	for (int i = 0; i < n; i++) {
		EXPECT_EQ(A[i], A_expected[i]);
	}
}

// Test a single element array, being sorted should return the array
TEST(InsertionSort, TestSingleElementArray) {
	int A[] = { 5 };
	int A_expected[] = { 5 };
	int n = sizeof(A) / sizeof(A[0]);
	insertion_sort(A, n);
	EXPECT_EQ(A[0], A_expected[0]);
}

// Test sorting with duplicate elements
TEST(InsertionSort, TestDuplicateElements) {
	int A[] = { 4,4,4,4,4,4,3,3,5,5,5 };
	int A_expected[] = { 3,3,4,4,4,4,4,4,5,5,5};
	int n = sizeof(A) / sizeof(A[0]);
	insertion_sort(A, n);
	for (int i = 0; i < n; i++) {
		EXPECT_EQ(A[i], A_expected[i]);
	}
}

// Test sorting with negative numbers
TEST(InsertionSort, TestNegativeNumbers) {
	int A[] = { -5, -3, -1, -4, -2 };
	int A_expected[] = { -5, -4, -3, -2, -1 };
	int n = sizeof(A) / sizeof(A[0]);
	insertion_sort(A, n);
	for (int i = 0; i < n; i++) {
		EXPECT_EQ(A[i], A_expected[i]);
	}
}

// Tests an already sorted array, the "best case" potentially
TEST(InsertionSort, TestAlreadySortedAscending) {
	int A[] = { 1, 2, 3, 4, 5 };
	int A_expected[] = { 1, 2, 3, 4, 5 };
	int n = sizeof(A) / sizeof(A[0]);
	insertion_sort(A, n);
	for (int i = 0; i < n; i++) {
		EXPECT_EQ(A[i], A_expected[i]);
	}
}

// Tests a descending array, the "worst case" potentially
TEST(InsertionSort, TestSortedDescending) {
	int A[] = { 5, 4, 3, 2, 1 };
	int A_expected[] = { 1, 2, 3, 4, 5 };
	int n = sizeof(A) / sizeof(A[0]);
	insertion_sort(A, n);
	for (int i = 0; i < n; i++) {
		EXPECT_EQ(A[i], A_expected[i]);
	}
}

// Test performance of insertion sort
TEST(InsertionSort, TestPerformance) {
	const int array_size = 100000;
	int* A = new int[array_size]; 
	srand(time(NULL));
	for (int i = 0; i < array_size; i++) {
		A[i] = rand() % array_size;
	}

	auto start = chrono::high_resolution_clock::now();
	insertion_sort(A, array_size);
	auto end = chrono::high_resolution_clock::now();
	auto duration = chrono::duration_cast<chrono::microseconds>(end - start);
	cout << "Execution time: " << duration.count()/1000 << " milliseconds" << endl;

	for (int i = 0; i < array_size - 1; i++) {
		EXPECT_TRUE(A[i] <= A[i + 1]);
	}
}