#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using str = string;

const int MAX_N = 1e5 + 5;
vector<int> g[MAX_N];
int dp[MAX_N];

int longest_path(int x) {
    int &r = dp[x];
    if (r != -1) return r;

    r = 0;
    for (auto v : g[x]) {
        r = max(r, longest_path(v) + 1);
    }

    return r;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    int x, y;
    for (int i = 0; i < m; i++) {
        cin >> x >> y;
        x--; y--;
        g[x].push_back(y);
    }

    memset(dp, -1, sizeof dp);

    int ans = -1;
    for (int i = 0; i < n; i++) {
        ans = max(ans, longest_path(i));
    }

    cout << ans << "\n";

    return 0;
}
