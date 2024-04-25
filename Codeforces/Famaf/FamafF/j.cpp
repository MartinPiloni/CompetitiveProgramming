#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using str = string;

#define sz(x) int((x).size())

const int MAXN = 5010;
int dp[MAXN][MAXN][2];
int n, m;
str a, b;

int f(int i, int j, int c) {
    if (i == n || j == m) return 0;

    int &r = dp[i][j][c];
    if (r != -1) return r;

    r = 0;
    if (c == 0) {
        if (a[i] == b[j]) {
            r += max(2 + f(i + 1, j + 1, 1), max(f(i + 1, j, 0), f(i, j + 1, 0)));
        } else {
            r += max(f(i + 1, j, 0), f(i, j + 1, 0)); 
        }
    } else {
        if (a[i] == b[j]) {
            r += f(i + 1, j + 1, 1) + 2;
        } else {
            r += max(f(i + 1, j, 1) - 1, max(f(i, j + 1, 1) - 1, 0));
        }
    }

    return r;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    memset(dp, -1, sizeof dp);

    cin >> n >> m;
    cin >> a >> b;
    
    cout << f(0, 0, 0) << "\n";

    return 0;
}
