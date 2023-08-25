#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define fst first
#define snd second
#define sz(x) ((int)x.size())
#define all(x) x.begin(),x.end()

using ll = long long;
using str = string;

const int MAXN = 55;
ll dp[MAXN][2];
ll a[MAXN];
int n;

ll f(int x, int c) {
    if (x == n) return 0;

    ll &r = dp[x][c];
    if (r != -1) return r;

    if (c == 0) r = max(a[x] + f(x + 1, !c), f(x + 1, c));
    else if (c == 1) r = min(a[x] + f(x + 1, c), f(x + 1, !c));
    return r;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    memset(dp, -1, sizeof dp);
    cin >> n;
    ll sum = 0;
    for (int i = 0; i < n; i++) {cin >> a[i]; sum += a[i];}

    cout << sum - f(0, 0) << " " << f(0, 0) << "\n";

    return 0;
}
