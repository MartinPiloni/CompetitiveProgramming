#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using str = string;

#define sz(x) (int) (x).size()

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

    vector<int> primes;
    for (int i = 2; i < 2000000; i++) {
        bool is_prime = true;
        for (int j = 2; j <= sqrt(i); j++) {
            if (i % j == 0) {
                is_prime = false;
                break;
            }
        }

        if (is_prime) {
            primes.push_back(i);
        }
   }

    ll ans = 0;
    for (int n: primes) {
        ans += n;
    }

    cout << ans << "\n";
    return 0;
}
