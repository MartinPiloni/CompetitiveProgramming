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
		int a, b, c;
		cin >> a >> b >> c;

		str ans = "NO\n";
		if (a * b < 0 || a * c < 0 || b * c < 0) {
			ans = "YES\n";
		}

		cout << ans;
	}

    return 0;
}
