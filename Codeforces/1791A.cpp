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
		char c;
		cin >> c;

		str s = "codeforces";
		bool f = false;
		for (int i = 0; i < (int) s.size(); i++) {
			if (c == s[i]) {
				f = true;
				break;
			}
		}

		if (f) {
			cout << "YES\n";
		}
		else {
			cout << "NO\n";
		}
	}

    return 0;
}
