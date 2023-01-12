#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using str = string;

#define sz(x) (int) (x).size()

void setIO(string name = "") {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
	if ((int) name.size()) {
		freopen((name + ".in").c_str(), "r", stdin);
		freopen((name + ".out").c_str(), "w", stdout);
	}
}

int main() {
	setIO("cowsignal");

	int m, n, k;
	cin >> m >> n >> k;

	vector<vector<char>> ans(m*k, vector<char>(n*k));
	str line;
	for (int i = 0; i < m; i++) {
		cin >> line;
		for (int j = 0; j < n; j ++) {
			for (int p = 0; p < k; p++) {
				for (int q = 0; q < k; q++) {
					ans[i*k + p][j*k + q] = line[j];
				}
			}
		}
	}

	for (int i = 0; i < m * k; i++) {
		for (int j = 0; j < n * k; j++) {
			cout << ans[i][j];
		}
		cout << "\n";
	}
    return 0;
}

//  Horrible solution :)