#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using str = string;

const int MAX_N = (int)1e5 + 5;
int n;
int a[MAX_N][3];
int dp[MAX_N][3];

int happiness(int d, int l) {
    if (d == n) return 0;

    int &r = dp[d][l];
    if (r != -1) return r;

    for (int i = 0; i < 3; i++) {
        if (i == l) continue;
        r = max(r, a[d][i] + happiness(d + 1, i));
    }

    return r; 
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    memset(dp, -1, sizeof dp);

    cin >> n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < 3; j++) {
            cin >> a[i][j];
        }
    }

    int ans = -1;
    for (int i = 0; i < 3; i++) {
        ans = max(ans, happiness(0, i));
    }

    cout << ans << "\n";

    return 0;
}
