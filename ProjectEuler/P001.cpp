#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using str = string;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	ll ans = 0;
	for (int i = 0; i < 1000; i++) {
		if (i % 3 == 0 || i % 5 == 0) {
			ans += i;
		}
	}

	cout << ans << "\n";

    return 0;
}
