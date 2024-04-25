#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using str = string;

#define sz(x) int((x).size())

const ll MOD = 1e9 + 7;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll n, x, pos;
    cin >> n >> x >> pos;

    vector<ll> factorial(n);
    factorial[0] = 1;
    for (int i = 1; i <= n; i++) {
        factorial[i] = (factorial[i - 1] % MOD * i % MOD) % MOD;
    }

    ll lt = x - 1, gt = n - x, l = 0, r = n, m;
    ll ans = 1;
    while (l < r) {
        m = (l + r) / 2;
        if (m < pos) {
            ans = (ans % MOD * lt % MOD) % MOD;
            lt--;
            l = m + 1;
        } else if (m > pos) {
            ans = (ans % MOD * gt % MOD) % MOD;
            gt--;
            r = m;
        } else {
            l = m + 1;
        }
    }

    cout << (ans % MOD * factorial[lt + gt] % MOD) % MOD << "\n";
    return 0;
}
