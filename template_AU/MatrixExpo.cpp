#include <bits/stdc++.h>
using namespace std;

using ll = long long;

const ll MOD = 1e9 + 7;

using Matrix = array<array<ll, 2>, 2>;

Matrix mul(Matrix a, Matrix b) {
	Matrix res = {{{0, 0}, {0, 0}}};
	for (int i = 0; i < 2; i++) {
		for (int j = 0; j < 2; j++) {
			for (int k = 0; k < 2; k++) {
				res[i][j] += a[i][k] * b[k][j];
				res[i][j] %= MOD;
			}
		}
	}

	return res;
}