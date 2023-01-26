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
		int a, b, c, d;
		cin >> a >> b >> c >> d;

		set<int> s;
		for (int i = a; i <= b; i++) {
			s.insert(i);
		}

		for (int i = c; i <= d; i++) {
			s.insert(i);
		}

		int ans = (int) s.size();
		cout << ans << "\n";
	}

    return 0;
}
