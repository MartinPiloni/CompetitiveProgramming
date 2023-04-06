#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using str = string;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int t;
	cin >> t;

	ll n;
	while(t--) {
		cin >> n;
		vector<ll> prime_factors;

		ll d = 2;
		while(n > 1) {
			if (n % d == 0) {
				n /= d;
				prime_factors.push_back(d);
			} else {
				d++;
			}
		}

		if(prime_factors[0] == prime_factors[1]) {
			cout << prime_factors[0] << " " << prime_factors[2] << "\n";
		} else {
			cout << prime_factors[1] << " " << prime_factors[0] << "\n";
		}
		prime_factors.clear();
	}

    return 0;
}

// TLE :(
