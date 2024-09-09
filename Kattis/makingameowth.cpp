#include <iostream>
#include "pch.h"
// https://open.kattis.com/contests/h3idua/problems/makingameowth
using namespace std;

int mainmeowth() {
	int N; // The Meowth will read every Nth page
	int P; // The number of pages you will read in one sitting
	int X; // How many minutes it takes you to read a page.
	int Y; // How many minutes it takes meowth to read a page
	cin >> N >> P >> X >> Y;
	int minutes = P * X + (P / (N - 1)) * Y;
	cout << minutes;
	//cout << "N " << N << " P " << P << " X " << X << " Y " << Y << endl;
	//cout << "test finished. Minutes = " << minutes ;
	return 0;
}