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
		int x;
		cin >> x;

		int ans = 0;
		if (x > 70 && x <= 100) {
			ans += 500;
		} else if (x > 100) {
			ans += 2000;
		}

		cout << ans << "\n";
	}

    return 0;
}
