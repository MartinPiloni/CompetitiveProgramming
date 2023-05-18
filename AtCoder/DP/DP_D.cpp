#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using str = string;

const int MAX_N = 100;
const int MAX_W = (int)1e5 + 5;
ll dp[MAX_N][MAX_W], v[MAX_N], w[MAX_N];
int N, W;

ll knapsack(ll x, ll c) {
    if (x == N) return 0;

    ll &r = dp[x][c];
    if (r != -1) return r;

    r = knapsack(x + 1, c);
    if (c - w[x] >= 0) {
        r = max(r, knapsack(x + 1, c - w[x]) + v[x]);
    }

    return r;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    memset(dp, -1, sizeof dp);

    cin >> N >> W;
    for (int i = 0; i < N; i++) {
        cin >> w[i] >> v[i];
    }

    cout << knapsack(0, W) << "\n";

    return 0;
}
