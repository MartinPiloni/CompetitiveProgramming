#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using str = string;

const int MAX_N = 1e3 + 5;
int MOD = 1e9 + 7;
str g[MAX_N];
int dp[MAX_N][MAX_N];
int h, w;

int paths(int x, int y) {
    if (x == h - 1 && y == w - 1) return 1;

    int &r = dp[x][y];
    if (r != -1) return r;

    r = 0;
    if (g[x][y + 1] == '#' && g[x + 1][y] == '#') {
        return r;
    }

    if (y != w - 1 && g[x][y + 1] != '#') {
        r = (r + paths(x, y + 1)) % MOD;
    }

    if (x != h - 1 && g[x + 1][y] != '#') {
        r = (r + paths(x + 1, y)) % MOD;
    }

    return r;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> h >> w;
    for (int i = 0; i < h; i++) {
        cin >> g[i];
    }

    memset(dp, -1, sizeof dp);
    
    cout << paths(0, 0) << "\n";

    return 0;
}
