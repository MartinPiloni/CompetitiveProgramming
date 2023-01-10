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
		str s;
		cin >> s;

		str a = "", b = "", c = "";
		a = s[0];
		c = s[sz(s) - 1];

		if (a == c || (a != c && s[1] == 'b')) {
			b = s.substr(1, sz(s) - 2);
		} else if (a == "a") {
			a = s.substr(0, sz(s) - 2);
			b = s[sz(s) - 2];
		} else if (a == "b") {
			b = s[1];
			c = s.substr(2);
		}

			cout << a << " " << b << " " << c << "\n";
	}

    return 0;
}
