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

		pair<int, int> pos(0, 0);
		bool ans = false;
		for (int i = 0; i < n; i++) {
			if (s[i] == 'L') {
				pos.first -= 1;
			} else if (s[i] == 'R') {
				pos.first += 1;
			} else if (s[i] == 'U') {
				pos.second += 1;
			} else if (s[i] == 'D') {
				pos.second -= 1;
			}
			if (pos.first == 1 && pos.second == 1) {
				ans = true;
				break;
			}
		}

		if (ans) {
			cout << "YES\n";
		} else {
			cout << "NO\n";
		}
	}

    return 0;
}
