#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using str = string;

#define sz(x) int((x).size())

const int MAXN = 1e5 + 10;
ll dp[MAXN][3];
ll v[MAXN], c[3];
ll n;

ll f(ll a, ll b) {
    if (b == 3) return 0;
    if (a == n) return -4e18;

    ll &r = dp[a][b];
    if (r != (ll)-4e18) return r;

    r = max(f(a + 1, b), v[a] * c[b] + f(a, b + 1));

    return r;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < 3; j++) {
            dp[i][j] = -4e18;
        }
    }

    for (int i = 0; i < 3; i++) {
        cin >> c[i];
    }

    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }

    cout << f(0, 0) << "\n";
    return 0;
}
