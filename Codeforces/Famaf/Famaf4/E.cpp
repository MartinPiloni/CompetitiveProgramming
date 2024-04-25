#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using str = string;

const int MAX_N = 1e5 + 10;
ll a[MAX_N], dp[MAX_N][4];
int n;
str s, h = "hard";

ll ambiguity(int x, int y) {
    if (x == n) return 0;
    if (y == 4) return 2e18;

    ll &r = dp[x][y];
    if (r != -1) return r;

    if (s[x] == h[y]) {
        r = min(ambiguity(x + 1, y) + a[x], ambiguity(x, y + 1));
    } else {
        r = ambiguity(x + 1, y);
    }

    return r;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    memset(dp, -1, sizeof dp);
    cin >> n >> s;
    for(int i = 0; i < n; i++) cin >> a[i];
    cout << ambiguity(0, 0) << "\n";

    return 0;
}
