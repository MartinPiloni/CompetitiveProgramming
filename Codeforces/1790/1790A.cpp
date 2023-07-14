#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using str = string;

#define sz(x) (int) (x).size()

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	str pi = "3141592653589793238462643383279";
	int t;
	cin >> t;
	while (t--) {
		str n;
		cin >> n;

		int ans = 0;
		for (int i = 0; i < (int) size(n); i++) {
			if (n[i] != pi[i]) {
				break;
			}
			ans++;
		}

		cout << ans << "\n";
	}

    return 0;
}
