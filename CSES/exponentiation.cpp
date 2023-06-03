#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using str = string;

#define sz(x) int((x).size())

const int MOD = 1e9 + 7;

ll pow (ll b, ll e, ll m) {
    if (e == 0) return 1;

    ll x;
    if (e % 2 == 0) {
        x = pow(b, e / 2, m) % m;
        return (x * x) % m;
    } else {
        x = pow(b, (e - 1) / 2, m) % m;
        return (((x * x) % m) * b) % m;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while(t--) {
        ll x, y;
        cin >> x >> y;
        cout << pow(x, y, MOD) << "\n";
    }
    return 0;
}
