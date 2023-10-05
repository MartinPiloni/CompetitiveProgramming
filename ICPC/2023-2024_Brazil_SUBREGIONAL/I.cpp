#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define fst first
#define snd second
#define sz(x) ((int)x.size())
#define all(x) x.begin(),x.end()

using ll = long long;
using str = string;

const int MAXN = 1e5 + 10;
ll dp[MAXN][2];
int n;
int v[MAXN];

ll f(int i, bool p) {
    if (i == n) return 0;

    ll &r = dp[i][p];
    if (r != -1) return r;

    if (p && v[i] == 0) {
        r = 1 + f(i + 1, p);
    } else if (v[i] == 0) {
        r = f(i + 1, p);
    } else if (!p && v[i] == 1) {
        r = 1 + f(i + 1, !p);
    } else {
        r = f(i + 1, !p);
    } 

    return r;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    memset(dp, -1, sizeof dp);

    cin >> n;
    for (int i = 0; i < n; i++) cin >> v[i];
    
    ll ans = 0;
    for (int i = 0; i < n; i++) ans += f(i, 0);
    cout << ans << "\n";

    return 0;
}
