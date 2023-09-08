#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using str = string;

#define sz(x) int((x).size())

void setIO(string name = "") {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    if ((int) name.size()) {
        freopen((name + ".in").c_str(), "r", stdin);
        freopen((name + ".out").c_str(), "w", stdout);
    }
}

const int MAXN = 1e3 + 10;
int dp[MAXN];
int x, y, m;

int f(int c) {
    if (x > c && y > c) return 0;

    int &r = dp[c];
    if (r != -1) return r;

    if (y <= c) {
        r = max(x + f(c - x), y + f(c - y));
    } else if (x <= c) {
        r = x + f(c - x);
    }

    return r;
}

int main() {
    setIO("pails");

    memset(dp, -1, sizeof dp);
    cin >> x >> y >> m;
    cout << f(m) << "\n";

    return 0;
}
