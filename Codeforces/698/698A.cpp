#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define fst first
#define snd second
#define sz(x) ((int)x.size())
#define all(x) x.begin(),x.end()

using ll = long long;
using str = string;

const int MAXN = 1e2 + 10;
int a[MAXN], dp[MAXN][4];
int n;

int f(int x, int l) {
    if (x == n) return 0;

    int &r = dp[x][l];
    if (r != -1) return r;

    if (a[x] == 0 || (a[x] == 1 && l == 2) || (a[x] == 2 && l == 3)) {
        r = 1 + f(x + 1, 1);
    } else if (a[x] == 1) {
        r = min(f(x + 1, 2), 1 + f(x + 1, 1));
    } else if (a[x] == 2) {
        r = min(f(x + 1, 3), 1 + f(x + 1, 1));
    } else if (a[x] == 3 && l != 2 && l != 3) {
        r = min({1 + f(x + 1, 1), f(x + 1, 2), f(x + 1, 3)});
    } else if (a[x] == 3 && l != 2) {
        r = min(1 + f(x + 1, 1), f(x + 1, 2));
    } else if (a[x] == 3 && l != 3) {
        r = min(1 + f(x + 1, 1), f(x + 1, 3));
    }

    return r;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    memset(dp, -1, sizeof dp);
    cin >> n;
    for (int i = 0; i < n; i++) cin >> a[i];

    cout << f(0, 0) << "\n";
    return 0;
}
