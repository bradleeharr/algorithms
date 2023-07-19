#include "pch.h"
#include "linear_search.h"
#include <chrono> 
using namespace std;

// Test to make sure that an arbitrary sorting works correctly
TEST(LinearSearch, TestArbitrarySubarraySearch) {
	// Test increasing sort
	int A[] = { 1,2,3,4,5,6,7,8,1,1,4,1,5,9,9,9,9,0,3,1,4,1,5 };
	int x[] = { 3,1,4,1,5 };
	int n = sizeof(A) / sizeof(A[0]);
	int k = sizeof(x) / sizeof(x[0]);
	int index = linear_search(A, n, x, k);
	EXPECT_EQ(index, 18);

}
