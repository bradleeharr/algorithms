#include "pch.h"
#include "insertion_sort.h"

using namespace std;
TEST(TestCaseName, TestName) {
	int A[] = { 1,3,5,7,9,10,8,6,4,2,0 };
	int n = sizeof(A) / sizeof(A[0]);
	insertion_sort(A, n);


	int A_expected[] = { 0,1,2,3,4,5,6,7,8,9,10 };
	for (int i = 0; i < n; i++) {
		EXPECT_EQ(A[i], A_expected[i]);
	}
	EXPECT_TRUE(true);
}