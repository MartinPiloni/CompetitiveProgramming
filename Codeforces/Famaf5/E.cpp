#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using str = string;

#define sz(x) int((x).size())

const int MOD = 1e9 + 7;
const int MAX_N = 1e6 + 5;
ll f[MAX_N], inv[MAX_N];

bool is_excellent(ll i, ll a, ll b) {
    bool ans = true;
    while (i != 0) {
        if (i % 10 != a && i % 10 != b) {
            ans = false;
            break;
        }

        i /= 10;
    }

    return ans;
}

ll exp(ll b, ll e) {
    if (e == 0) return 1;

    ll x;
    if (e % 2 == 0) {
        x = exp(b, e / 2);
        return (x * x) % MOD;
    } else {
        x = exp(b, (e - 1) / 2);
        return (((x * x) % MOD) * b) % MOD;
    }
}

ll ncr(ll n, ll k) {
    if (n == k) return 1;
    if (k == 1) return n; 
    return (((f[n] * inv[n - k]) % MOD) * inv[k]) % MOD;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    ll a, b, n;
    cin >> a >> b >> n;

    f[0] = 1;
    for (int i = 1; i <= n; i++) {
        f[i] = i * f[i - 1] % MOD;
    }

	inv[n] = exp(f[n], MOD - 2);
	for (ll i = n; i >= 1; i--) { 
        inv[i - 1] = inv[i] * i % MOD; 
    }

    ll ans = 0; 
    pair<ll, ll> p = {n, 0};
    for (ll i = n * a; i <= n * b; i += b - a) {
        if (is_excellent(i, a, b)) {
            ans = (ans + ncr(n, p.first)) % MOD;
        }
        p.first--;
        p.second++;
    }

    cout << ans << "\n";
    return 0;
}
