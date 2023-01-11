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
		int x, y;
		cin >> x >> y;

		if (y / 3 >= x) {
			cout << "YES\n";
		} else {
			cout << "NO\n";
		}
	}

    return 0;
}
