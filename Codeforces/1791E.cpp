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

		vector<ll> a(n);
		ll sum = 0, c = 0, m = 1e9;
		for (int i = 0; i < n; i++) {
			cin >> a[i];
			if (a[i] <= 0) {
				c++;
			}
			m = min(m, abs(a[i]));
			sum += abs(a[i]);
		}

		if (c % 2 == 0) {
			cout << sum << "\n";
		} else {
			cout << sum - 2*m << "\n";
		}
	}

    return 0;
}
