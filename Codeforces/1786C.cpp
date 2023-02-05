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

		vector<ll> hp(n);
		for (int i = 0; i < n; i++) {
			cin >> hp[i];
		}

		sort(hp.begin(), hp.end());

		ll ans = 0;
		int j = 1;
		for (int i = 0; i < n; i++) {
			if(j < hp[i]) {
				ans += hp[i] - j;
				j++;
			}
		}

		cout << ans << "\n";
	}

    return 0;
}
