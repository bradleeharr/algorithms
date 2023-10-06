#include <iostream>
#include "pch.h"
// https://open.kattis.com/contests/h3idua/problems/pulverizingpancake
using namespace std;

int mainpancake() {
	int N; // Number of Columns in the World
	int M; // Number of Columns with Wild Pokemon in them
	cin >> N >> M;

	string A; // String telling you if there are pokemon in a column
	cin >> A;

	int col = 0;
	int pancakes = 0;
	while (col < N) {
		if (A[col] == '1') {
			// Run down this row with Pulverizing Pancake
			pancakes++;
			A[col] = '0';
			// if possible, push from the right adjacent column to
			// the next right nonadjacent column
			if (col < N - 2 && A[col + 1] == '1') {
				A[col + 1] = '0';
				A[col + 2] = '1';
			}
		}
		col++;
	}
	cout << pancakes;
	//cout << "N " << N << " P " << P << " X " << X << " Y " << Y << endl;
	//cout << "test finished. Minutes = " << minutes ;
	return 0;
}