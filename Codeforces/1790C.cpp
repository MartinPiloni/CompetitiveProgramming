#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using str = string;

#define sz(x) (int) (x).size()

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int t;
	cin >> t;

	while (t--) {
		int n;
		cin >> n;

		vector<vector<int>> p(n, vector<int>(n - 1));
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n - 1; j++) {
				cin >> p[i][j];
			}
		}

		vector<int> ans(n);

		int a, b = -1;
		a = p[0][0];
		for (int i = 1; i < n; i++) {
			if (p[i][0] != a) {
				b = p[i][0];
			}
		}

		int occ_a = 0, occ_b = 0;
		for (int i = 0; i < n; i++) {
			if (p[i][0] == a) {
				occ_a++;
			} else {
				occ_b++;
			}
		}

		if (occ_b > occ_a) {
			int tmp = b;
			b = a;
			a = tmp;
		}

		ans[0] = a;
		ans[1] = b;
		a = b;
		for (int j = 1; j < n - 1; j++) {
			for (int i = 0; i < n; i++) {
				if(p[i][j] != a) {
					ans[j + 1] = p[i][j];
					a = p[i][j];
					break;
				}
			}
		}

		for (int i = 0; i < n; i++) {
			cout << ans[i] << " \n"[i == n - 1];
		}
	}

    return 0;
}
