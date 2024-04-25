#include <bits/stdc++.h>
using namespace std;

using ll = __int128_t;
using str = string;

#define sz(x) int((x).size())

vector<pair<ll, ll>> prime_factorization(ll n) {
    vector<pair<ll, ll>> ret;
    for (ll i = 2; i * i <= n; i++) {
        if (n % i == 0) {
            ret.push_back({i, 0});
            while (n % i == 0) {
                ret.back().second++;
                n /= i;
            }
        }
    }

    if (n > 1) ret.push_back({n, 1});
    return ret;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    long long n, b;
    cin >> n >> b;

    vector<pair<ll, ll>> primes = prime_factorization(b);
    ll ans = 1e18;
    for (int i = 0; i < sz(primes); i++) {
        ll s = 0, p = primes[i].first;
        while(n >= p) {
            s += n / p;
            if (p * primes[i].first > 0) p *= primes[i].first;
            else break;
        }
        ans = min(ans, s / primes[i].second);
    }
    
    cout << (long long)ans << "\n";
    return 0;
}
