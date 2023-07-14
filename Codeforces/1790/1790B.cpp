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
		int n, s, r;
		cin >> n >> s >> r;

		int max_value = s - r;
		vector<int> ans(n);
		ans[0] = max_value;

		int partial_sum = 0;
		partial_sum += max_value;
		for (int i = 1; i < n; i++) {
			for (int j = max_value; j > 0; j--) {
				if (partial_sum + j <= s && partial_sum + j + (n - i - 1) <= s) {
					partial_sum += j;
					ans[i] = j;
					break;
				}
			}
		}

		for (int i = 0; i < n; i++) {
			cout << ans[i] << " \n"[i == n-1];
		}
	}
    return 0;
}
