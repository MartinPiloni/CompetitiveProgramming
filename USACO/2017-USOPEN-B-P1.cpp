#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using str = string;

#define sz(x) (int) (x).size()

void setIO(string name = "") {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
	if ((int) name.size()) {
		freopen((name + ".in").c_str(), "r", stdin);
		freopen((name + ".out").c_str(), "w", stdout);
	}
}

int main() {
	setIO("lostcow");

	int x, y;
	cin >> x >> y;

	int ans = 0, i = 1, pos = x, previous_pos = x;
	if (x < y) {
		while (pos < y) {
			pos = x + i;
			ans += abs(previous_pos - pos);
			i *= -2;
			previous_pos = pos;
		}
		ans -= pos - y;
	}
	else if (x > y) {
		while (pos > y) {
			pos = x + i;
			ans += abs(previous_pos - pos);
			i *= -2;
			previous_pos = pos;
		}
		ans -= y - pos;
	}

	cout << ans << "\n";
    return 0;
}
