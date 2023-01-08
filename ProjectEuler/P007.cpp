#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using str = string;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	ll n = 2;
	vector<ll> primes;
	bool is_prime;

	while ((int) primes.size() != 10001) {
		is_prime = true;
		for (ll p: primes) {
			if (n % p == 0) {
				is_prime = false;
				break;
			}
		}

		if (is_prime) {
			primes.push_back(n);
		}
		n++;
	}

	cout << primes.back() << "\n";
    return 0;
}
