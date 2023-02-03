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
		str s;
		cin >> n >> s;

		int ans = n;
		for (int i = 0; i < n / 2; i++) {
			if (s[i] != s[n - i - 1] ) {
				ans -= 2;
			} else {
				break;
			}
		}
		cout << ans << "\n";
	}

    return 0;
}
