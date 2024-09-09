#include "pch.h"
#include "insertion_sort.h"
#include <chrono> 
using namespace std;

// Test to make sure that an arbitrary sorting works correctly
TEST(InsertionSort, TestArbitrarySort) {
	// Test increasing sort
	int A[] = { 1,3,5,7,9,10,8,6,4,2,0 };
	int n = sizeof(A) / sizeof(A[0]);
	insertion_sort(A, n);
	EXPECT_TRUE(is_increasing(A, n));

	// Test decreasing sort
	int B[] = { 1,3,5,7,9,10,8,6,4,2,0 };
	n = sizeof(B) / sizeof(B[0]);
	insertion_sort_decreasing(B, n);
	EXPECT_TRUE(is_decreasing(B, n));
}