#include <iostream>
#include "pch.h"
#include "insertion_sort.h"

int* insertion_sort(int* A, int n) {
	for (int i = 1; i < n; i++) {
		int key = A[i];
		// Insert A[i] into the sorted subarray A[0:i-1]
		int j = i - 1;
		while (j > -1 && A[j] > key) {
			A[j + 1] = A[j];
			j = j - 1;
		}
		A[j + 1] = key;

	
		// Debug Logging to see the sorting going on : 
		if (n < 20) {
			for (int i = 0; i < n; i++) {
				std::cout << A[i] << " ";
			} 		std::cout << "| key: " << key << " | ";
			std::cout << std::endl;
		}
	}
	return A;

}