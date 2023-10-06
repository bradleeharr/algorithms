#include <iostream>
#include <vector>
#include "pch.h"
// https://open.kattis.com/contests/h3idua/problems/gymleadersterritory 
using namespace std;
int main() {
	int n, k, m; // number of other gym leaders; rival gym leader; total number of alliances
	cin >> n >> k >> m;
	vector<vector<int>> alliances = vector<vector<int>>(m);
	int p1;
	int p2;
	for (int i = 0; i < m; i++) {
		cin >> p1 >> p2;
		alliances[p1].push_back(p2);
		alliances[p2].push_back(p1);
	}
	for (int i = 0; i < m; i++) {
		cout << " ALLIANCES FOR GYM LEADER " << i << endl;
		for (int j = 0; j < alliances[i].size(); j++)
			cout << alliances[i][j] << endl;
	}
	//cout << "N " << N << " P " << P << " X " << X << " Y " << Y << endl;
	//cout << "test finished. Minutes = " << minutes ;
	return 0;
}