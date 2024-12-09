#include "solveSystemGauss.h"
#include <iostream>
#include <vector>
#include <locale.h>
using namespace std;
int main() {
	setlocale(LC_ALL, "ru");
	cout << "������� n � m:\n";
	int n, m;
	cin >> n >> m;
	vector<vector<double>> a(n, vector<double>(m));
	cout << "������� �������:\n";
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			cin >> a[i][j];
		}
	}
	solveSystemGauss(a, n, m);
	cout << "���������:\n";
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			cout << a[i][j] << ' ';
		}
		cout << '\n';
	}
	return 0;
}