#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using str = string;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);


	ll a, b, c;
	a = 0;
	b = 1;

	ll ans = 0;
	while (a < 4000000) {
		c = a + b;
		a = b;
		b = c;
		if (b % 2 == 0) {
			ans += b;
		}
	}

	cout << ans << "\n";
    return 0;
}
