#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using db = double;
using str = string;

#define sz(x) (int) (x).size()

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int t;
	cin >> t;
	while (t--) {
		int n, y;
		cin >> n >> y;

		ll bitwise_or;
		ll temp;
		for (int i = 0; i < n; i++) {
			if (i == 0) {
				cin >> bitwise_or;
			} else {
				cin >> temp;
				bitwise_or |= temp;
			}
		}

		ll ans = -1;
		for (int i = 0; i <= y; i++) {
			if ((bitwise_or | i) == y) {
				ans = i;
				break;
			}
		}

		cout << ans << "\n";
	}

    return 0;
}
