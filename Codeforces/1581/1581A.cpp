#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using str = string;

const ll MAX_N = 2e5 + 5;
const ll MOD = 1e9 + 7;
ll fact[MAX_N];

ll exp(int b, int e) {
    if (e == 0) return 1;

    ll x;
    if (e % 2 == 0) {
        x = exp(b, e / 2) % MOD;
        return (x * x) % MOD;
    }
    else {
        x = exp(b, (e - 1) / 2);
        return (((x * x) % MOD) * b) % MOD; 
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    fact[0] = 1LL;
    for (ll i = 1; i < (ll)2e5 + 5; i++) {
        fact[i] = (i * fact[i - 1]) % MOD;
    }

    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;

        n *= 2;
        cout << (fact[n] * exp(2, MOD - 2)) % MOD  << "\n";
    }

    return 0;
}
