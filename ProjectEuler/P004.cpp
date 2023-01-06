#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using str = string;

ll reverse_ll(ll n) {
	ll ans = 0;

	while (n > 0) {
		ans = (ans * 10) + n % 10;
		n /= 10;
	}

	return ans;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	const int UPPER_BOUND = 999;
	const int LOWER_BOUND = 100;

	ll n;
	ll ans = 0;
	for (ll i = UPPER_BOUND; i >= LOWER_BOUND; i--) {
		for (ll j = i; j >= LOWER_BOUND; j--) {
			n = i * j;
			if (n <= ans) {
                break;
			}
			else if (n == reverse_ll(n)) {
				ans = n;
			}
		}
	}

	cout << ans << "\n";
    return 0;
}
