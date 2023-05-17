#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using str = string;

const int MAX_N = (int)1e5 + 10;
int dp[MAX_N];
int h[MAX_N];

int cost(int p) {
    if (dp[p] != -1) return dp[p];

    dp[p] = min(abs(h[p] - h[p + 1]) + cost(p + 1), 
                abs(h[p] - h[p + 2]) + cost(p + 2));

    return dp[p];
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    memset(dp, -1, sizeof(dp));
    int n;
    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> h[i];
    }

    dp[n - 1] = 0;
    dp[n - 2] = abs(h[n - 2] - h[n - 1]);
    cout << cost(0) << "\n";

    return 0;
}
