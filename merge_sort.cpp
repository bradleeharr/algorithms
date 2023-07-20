#include "pch.h"
#include "merge_sort.h"

// Merge:
// A : Base array
// p : beginning index of merge
// q : midpoint index of merge
// r : final index of merge
void merge(int* A, int p, int q, int r) {
	int n_l = q - p + 1;
	int n_r = r - q;
	int* L = new int[n_l];
	int* R = new int[n_r];
	// Copy A[p:q] into L[0:n_L - 1]
	for (int i = 0; i < n_l; i++) {
		L[i] = A[p + i];
	}
	// Copy A[q+1:r] into R[0:n_r - 1]
	for (int j = 0; j < n_r; j++) {
		R[j] = A[q + j + 1];
	}
	// As long as each of the arrays L and R contains an unmerged element,
	// copy the smallest unmerged element back into A[p:r]
	int i = 0; // i indexes the smallest remaining element in L
	int j = 0; // j indexes the smallest remaining element in R
	int k = p; // k indexes the location in A to fill
	while (i < n_l && j < n_r) {
		if (L[i] <= R[j]) {
			A[k] = L[i];
			i = i + 1;
		}
		else {
			A[k] = R[j];
			j = j + 1;
		}
		k = k + 1;
	}
	// Having gone through one of L and R entirely, copy the remainder
	// of the other to the end of A[p:r]
	while (i < n_l) {
		A[k] = L[i];
		i = i + 1;
		k = k + 1;
	}
	while (j < n_r) {
		A[k] = R[j];
		j = j + 1;
		k = k + 1;
	}
}


// Merge Decreasing:
// A : Base array
// p : beginning index of merge
// q : midpoint index of merge
// r : final index of merge
void merge_decreasing(int* A, int p, int q, int r) {
	int n_l = q - p + 1;
	int n_r = r - q;
	int* L = new int[n_l];
	int* R = new int[n_r];
	// Copy A[p:q] into L[0:n_L - 1]
	for (int i = 0; i < n_l; i++) {
		L[i] = A[p + i];
	}
	// Copy A[q+1:r] into R[0:n_r - 1]
	for (int j = 0; j < n_r; j++) {
		R[j] = A[q + j + 1];
	}
	// As long as each of the arrays L and R contains an unmerged element,
	// copy the smallest unmerged element back into A[p:r]
	int i = 0; // i indexes the smallest remaining element in L
	int j = 0; // j indexes the smallest remaining element in R
	int k = p; // k indexes the location in A to fill
	while (i < n_l && j < n_r) {
		if (L[i] >= R[j]) {
			A[k] = L[i];
			i = i + 1;
		}
		else {
			A[k] = R[j];
			j = j + 1;
		}
		k = k + 1;
	}
	// Having gone through one of L and R entirely, copy the remainder
	// of the other to the end of A[p:r]
	while (i < n_l) {
		A[k] = L[i];
		i = i + 1;
		k = k + 1;
	}
	while (j < n_r) {
		A[k] = R[j];
		j = j + 1;
		k = k + 1;
	}
}


// Merge Sort
// A : Array to sort
// p : beginning of part to sort
// r : end of part to sort
void merge_sort(int* A, int p, int r)
{
	if (p >= r) return;
	int q = (p + r) / 2;
	merge_sort(A, p, q);
	merge_sort(A, q + 1, r);
	// Merge[p:q] and A[q+1:r] into A[p:r]
	merge(A, p, q, r);
}

void merge_sort_decreasing(int* A, int p, int r)
{
	if (p >= r) return;
	int q = (p + r) / 2;
	merge_sort_decreasing(A, p, q);
	merge_sort_decreasing(A, q + 1, r);
	// Merge[p:q] and A[q+1:r] into A[p:r]
	merge_decreasing(A, p, q, r);
}
