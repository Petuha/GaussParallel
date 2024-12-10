#include "solveSystemGauss.h"
#include <iostream>
#include <vector>
#include <locale.h>
using namespace std;
int main() {
	setlocale(LC_ALL, "ru");
	cout << "¬ведите n и m:\n";
	int n, m;
	cin >> n >> m;
	vector<vector<double>> a(n, vector<double>(m));
	cout << "¬ведите матрицу:\n";
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			cin >> a[i][j];
		}
	}
	solveSystemGauss(a, n, m);
	cout << "–езультат:\n";
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			cout << a[i][j] << ' ';
		}
		cout << '\n';
	}
	return 0;
}
/*
5 7
0 0 0 2 1 0 1
0 0 0 0 0 0 0
0 0 1 2 0 0 3
1 2 3 4 0 0 4
0 0 0 1 2 0 5

--------------
0 0 0 1 0 0 -1
0 0 0 0 0 0 0
0 0 1 0 0 0 5
1 2 0 0 0 0 -7
0 0 0 0 1 0 3
*/