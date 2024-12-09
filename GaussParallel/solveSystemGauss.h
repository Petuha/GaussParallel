#pragma once
template <class T>
void solveSystemGauss(T& a, int n, int m) {
	for (int i = 0; i < n; ++i) {
		auto find_first_not_zero = [&]() -> int {
			int min_j = m;
#pragma omp parallel
			{
				int loc_j = m;
#pragma omp for
				for (int j = 0; j < m; ++j) {
					if (a[i][j] != 0) {
						loc_j = j;
						break;
					}
				}
#pragma omp critical
				{
					if (loc_j < min_j) min_j = loc_j;
				}
			}
			return min_j;
			};
		auto divide_string = [&](int in) {
#pragma omp parallel
			{
#pragma omp for
				for (int j = in + 1; j < m; ++j) {
					a[i][j] /= a[i][in];
				}
			}
			a[i][in] = 1;
			};
		auto make_direct_step = [&](int in) {
#pragma omp parallel
			{
#pragma omp for
				for (int k = i + 1; k < n; ++k) {
					for (int j = in + 1; j < m; ++j) {
						a[k][j] -= a[i][j] * a[k][in];
					}
					a[k][in] = 0;
				}
			}
			};
		auto make_reversed_step = [&](int in) {
#pragma omp parallel
			{
#pragma omp for
				for (int k = i - 1; k >= 0; --k) {
					for (int j = in + 1; j < m; ++j) {
						a[k][j] -= a[i][j] * a[k][in];
					}
					a[k][in] = 0;
				}
			}
			};
		int index = find_first_not_zero();
		if (index >= m) continue;
		divide_string(index);
		make_direct_step(index);
		make_reversed_step(index);
	}
}