#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using str = string;

const int MAX_N = 3005;
str s, t;
int dp[MAX_N][MAX_N];
string ans = "";

int f(int x, int y) {
    if (x == (int) s.size() || y == (int)t.size()) return 0;

    int &r = dp[x][y];
    if (r != -1) return r;

    r = max(f(x + 1, y), f(x, y + 1));
    if(s[x] == t[y]) {
        r = max(r, f(x + 1, y + 1) + 1);
    }

    return r;
}

void build(int x, int y) {
    if (x == (int) s.size() || y == (int)t.size()) return;

    int res = f(x, y);
    if (s[x] == t[y]) {
        ans += s[x];
        build(x + 1, y + 1);
    } else if (res == f(x + 1, y)) {
        build(x + 1, y);
    } else {
        build(x, y + 1);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    memset(dp, -1, sizeof dp);
    cin >> s >> t;

    build(0, 0);
    cout << ans << "\n";

    return 0;
}
