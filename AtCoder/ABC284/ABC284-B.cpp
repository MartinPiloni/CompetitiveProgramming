#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using str = string;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int t;
	cin >> t;

	int n, num, ans;
	while (t--) {
		cin >> n;
		ans = 0;

		for (int i = 0; i < n; i++) {
			cin >> num;
			if (num % 2 == 1) {
				ans += 1;
			}
		}

		cout << ans << "\n";

	}
    return 0;
}
