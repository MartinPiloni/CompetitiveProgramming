#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define fst first
#define snd second
#define sz(x) ((int)x.size())
#define all(x) x.begin(),x.end()

using ll = long long;
using str = string;

const int MAXN = 2e5 + 10;
ll dp[MAXN][2];
int n;
str s;

ll f(int p, int c) {
    if (p == n) return 0;

    ll &r = dp[p][c];
    if (r != -1) return r;

    if (c != s[p] - '0') {
        r = 1 + f(p + 1, !c);
    } else {
        r = f(p + 1, c);
    }

    return r;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    memset(dp, -1, sizeof dp);

    int t;
    cin >> t;
    while (t--) {
        cin >> n >> s;

        ll ans = sz(s);
        for (int i = 0; i < n; i++) ans += f(i, s[i] - '0');
        cout << ans << "\n";

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < 2; j++) {
                dp[i][j] = -1;
            }
        }
    }

    return 0;
}
