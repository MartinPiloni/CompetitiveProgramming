#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define fst first
#define snd second
#define sz(x) ((int)x.size())
#define all(x) x.begin(),x.end()

using ll = long long;
using str = string;

const int MAXN = 1e3 + 10;
str g[MAXN];
ll dp[MAXN][MAXN];
int n, m;

ll f(int x, int y) {
    if (x == 0 || y == 0) return 1;

    ll &r = dp[x][y];
    if (r != -1) return r;

    r = 1;
    if (g[x][y] == g[x][y - 1] && g[x - 1][y] == g[x - 1][y - 1]) {
        r = min({f(x - 1, y - 1) + 1, f(x - 1, y) + 1, f(x, y - 1) + 1});
    } 

    return r;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    memset(dp, -1, sizeof dp);

    cin >> n >> m;
    for (int i = 0; i < n; i++) cin >> g[i];

    ll ans = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            ans = max(ans, f(i, j));
        }
    }
    cout << ans * ans << "\n";

    return 0;
}
