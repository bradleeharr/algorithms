#include "pch.h"
#include "merge_sort.h"
#include "insertion_sort.h"
#include <chrono> 
using namespace std;

// Test to make sure that an arbitrary sorting works correctly
TEST(MergeSort, TestArbitrarySort) {
	// Test increasing sort
	int A[] = { 1,3,5,7,9,10,8,6,4,2,0 };
	int n = sizeof(A) / sizeof(A[0]);
	merge_sort(A, 0, n-1);
	EXPECT_TRUE(is_increasing(A, n));

	// Test decreasing sort
	int B[] = { 1,3,5,7,9,10,8,6,4,2,0 };
	n = sizeof(B) / sizeof(B[0]);
	merge_sort_decreasing(B, 0, n-1);
	EXPECT_TRUE(is_decreasing(B, n));
}

// Test a single element array, being sorted should return the array
TEST(MergeSort, TestSingleElementArray) {
	// Test increasing sort
	int A[] = { 5 };
	int A_expected[] = { 5 };
	int n = sizeof(A) / sizeof(A[0]);
	merge_sort(A, 0, n-1);
	EXPECT_EQ(A[0], A_expected[0]);

	// Test decreasing sort
	int B[] = { 5 };
	int B_expected[] = { 5 };
	n = sizeof(B) / sizeof(B[0]);
	merge_sort_decreasing(B, 0, n-1);
	EXPECT_EQ(B[0], B_expected[0]);
}

// Test sorting with duplicate elements
TEST(MergeSort, TestDuplicateElements) {
	// Test increasing sort
	int A[] = { 4,4,4,4,4,4,3,3,5,5,5 };
	int n = sizeof(A) / sizeof(A[0]);
	merge_sort(A, 0, n-1);
	EXPECT_TRUE(is_increasing(A, n));

	//Test decreasing sort
	int B[] = { 4,4,4,4,4,4,3,3,5,5,5 };
	n = sizeof(B) / sizeof(B[0]);
	merge_sort_decreasing(B, 0, n-1);
	EXPECT_TRUE(is_decreasing(B, n));

}

// Test sorting with negative numbers
TEST(MergeSort, TestNegativeNumbers) {
	// Test increasing sort 
	int A[] = { -5, -3, -1, -4, -2 };
	int n = sizeof(A) / sizeof(A[0]);
	merge_sort(A, 0, n-1);
	EXPECT_TRUE(is_increasing(A, n));

	// Test decreasing sort
	int B[] = { -5, -3, -1, -4, -2 };
	n = sizeof(B) / sizeof(B[0]);
	merge_sort_decreasing(B, 0, n-1);
	EXPECT_TRUE(is_decreasing(B, n));
}

// Tests an already increasing sorted array, the "best case" potentially
TEST(MergeSort, TestAlreadySortedAscending) {
	// Test increasing sort
	int A[] = { 1, 2, 3, 4, 5 };
	int A_expected[] = { 1, 2, 3, 4, 5 };
	int n = sizeof(A) / sizeof(A[0]);
	merge_sort(A, 0, n-1);
	EXPECT_TRUE(is_increasing(A, n));
}

// Tests a descending array, the "worst case" potentially
TEST(MergeSort, TestSortedDescending) {
	// Test increasing sort
	int A[] = { 5, 4, 3, 2, 1 };
	int n = sizeof(A) / sizeof(A[0]);
	merge_sort(A, 0, n-1);
	EXPECT_TRUE(is_increasing(A, n));

	// Test decreasing sort
	int B[] = { 5, 4, 3, 2, 1 };
	n = sizeof(B) / sizeof(B[0]);
	merge_sort_decreasing(B, 0, n-1);
	EXPECT_TRUE(is_decreasing(B, n));
}

// Test performance of Merge sort
TEST(MergeSort, TestPerformance) {
	const int array_size = 10000;
	int* A = new int[array_size];
	srand(time(NULL));
	for (int i = 0; i < array_size; i++) {
		A[i] = rand() % array_size;
	}

	auto start = chrono::high_resolution_clock::now();
	merge_sort(A, 0, array_size-1);
	auto end = chrono::high_resolution_clock::now();
	auto duration = chrono::duration_cast<chrono::microseconds>(end - start);
	cout << "Execution time for " << array_size << " elements : " << duration.count() / 1000 << " milliseconds" << endl;

	EXPECT_TRUE(is_increasing(A, array_size));

}