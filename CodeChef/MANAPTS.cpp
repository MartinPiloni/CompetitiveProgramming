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
		int x, y;
		cin >> x >> y;

		int ans = y / x;
		cout << ans << "\n";
	}
    return 0;
}
