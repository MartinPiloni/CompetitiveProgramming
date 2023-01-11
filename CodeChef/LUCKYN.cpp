#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using db = double;
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
		bool lucky = false;
		while (x > 1) {
			if (x % 10 == 7) {
				lucky = true;
				break;
			}
			x /= 10;
		}
		if (lucky) {
			cout << "YES\n";
		} else {
			cout << "NO\n";
		}
	}

    return 0;
}
