#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define fst first
#define snd second
#define sz(x) ((int)x.size())
#define all(x) x.begin(),x.end()

using ll = long long;
using str = string;

const int MAXN = 60;
const int MAXS = 2.5e3 + 10;
ll dp[MAXN][MAXS][MAXN];
int v[MAXN];
int n, a;

ll f(int x, int s, int t) {
    if (x == n && t != 0 && ((long double)s / t) == a) return 1;
    else if (x == n) return 0;

    ll &r = dp[x][s][t];
    if (r != -1) return r;

    r = f(x + 1, s + v[x], t + 1) + f(x + 1, s, t);
    return r;
}



int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    memset(dp, -1, sizeof dp);
    cin >> n >> a;
    for (int i = 0; i < n; i++) cin >> v[i];
    cout << f(0, 0, 0) << "\n";
    return 0;
}
