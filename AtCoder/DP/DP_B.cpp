#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using str = string;

const int MAX_N = 1e5 + 10;
int n, k;
int dp[MAX_N];
int h[MAX_N];

int cost(int p) {
    if (dp[p] != -1) return dp[p];

    if (p == n - 1) {
        dp[p] = 0;
        return dp[p];
    }

    dp[p] = (int) 1e9;
    for (int i = 1; i <= min(k, n - 1 - p); i++) {
        dp[p] = min(dp[p], abs(h[p] - h[p + i]) + cost(p + i));
    }
    return dp[p];
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    memset(dp, -1, sizeof(dp));
    cin >> n >> k;
    for (int i = 0; i < n; i++) cin >> h[i];

    dp[n - 1] = 0;
    cout << cost(0) << "\n";

    return 0;
}
