#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using str = string;

const int MAX_N = 3e5 + 10;
ll dp[MAX_N][2];
ll x, y, z;
str s;

ll f(ll p, bool c) {
    if (p == (int)s.size()) return 0;

    ll &r = dp[p][c];
    if (r != -1) return r;

    if ((s[p] == 'a' && c == 0) || (s[p] == 'A' && c == 1)) {
        r = min(f(p + 1, c) + x, f(p + 1, c == 0) + y + z);
    } else {
        r = min(f(p + 1, c) + y, f(p + 1, c == 0) + z + x);
    }

    return r;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> x >> y >> z >> s;
    memset(dp, -1, sizeof dp);
    cout << f(0, 0) << "\n";
    return 0;
}
