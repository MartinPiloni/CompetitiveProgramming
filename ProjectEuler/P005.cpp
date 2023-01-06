#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using str = string;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	ll ans = 20;
	bool divisible = false;
	while(!divisible) {
		for (int i = 3; i <= 20; i++) {
		// If a number is divisible by 20 its also divisible by 2
			if (ans % i != 0) {
				// To be divisible by 20 we have to increase by 20
				ans += 20;
				break;
			} else if (i == 20) {
				divisible = true;
			}
		}
	}

	cout << ans << "\n";
    return 0;
}
