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
const int MAXK = 12 * 1e3 + 10;
ll dp[MAXN][MAXK];
ll a[MAXN][12];
int n, k;

ll f(int i, int c) {
    if (i == n || c >= k) return 0;

    ll &r = dp[i][c];
    if (r != -1) return r;

    ll acc = 0;
    for (int j = 0; j < 12; j++) {
        if (c + j >= k) break;

        acc += a[i][j];
        r = max(r, acc + f(i + 1, c + j + 1));
    }
    r = max(r, f(i + 1, c));

    return r;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    memset(dp, -1, sizeof dp);
    cin >> n >> k;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < 12; j++) {
            cin >> a[i][j];
        }
    }
    cout << f(0, 0) << "\n";

    return 0;
}
