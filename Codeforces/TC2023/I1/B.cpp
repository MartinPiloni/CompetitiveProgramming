#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define fst first
#define snd second
#define sz(x) ((int)x.size())
#define all(x) x.begin(),x.end()

using ll = long long;
using str = string;

const int MAXN = 1e6 + 10;
ll dp[MAXN];
int v[MAXN];
int n;

ll f(int i) {
    if (i >= n) return 0;

    ll &r = dp[i];
    if (r != -1) return r;

    r = max(v[i] + f(i + 3), f(i + 1));
    return r;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    memset(dp, -1, sizeof dp);
    cin >> n;
    for (int i = 0; i < n; i++) cin >> v[i];
    cout << f(0) << "\n";

    return 0;
}
