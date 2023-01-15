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
		int N;
		cin >> N;
		vector<ll> a(2*N);

		for (int i = 0; i < 2*N; i++) {
			cin >> a[i];
		}

		sort(a.begin(), a.end());
		ll ans = a[N - 1] - a[0];

		for (int i = N; i < 2*N; i++) {
			ans = min(ans, a[i] - a[i - N + 1]);
		}

		cout << ans << "\n";
	}

    return 0;
}
