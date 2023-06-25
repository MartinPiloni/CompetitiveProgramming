#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using str = string;

#define sz(x) int((x).size())

const int MAXN = 2e5 + 10;
ll dp[MAXN], f[MAXN];
bool vis[MAXN];
vector<int> g[MAXN];

void dfs(int v) {
    vis[v] = true;

    for (auto p : g[v]) {
        if (!vis[p]) {
            f[p] = v;
            dfs(p);
        }
    }
}

ll s(int v) {
    ll &r = dp[v];
    if(r != -1) return r;

    if (v != 0 && sz(g[v]) == 1) {
        r = 1;
        return r;
    }

    r = 0;
    for (auto p : g[v]) {
        if (p != f[v]) {
            r += s(p);
        }
    }

    return r;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    memset(dp, -1, sizeof dp);
    while(t--) {
        int n;
        cin >> n;

        int x, y;
        for (int i = 0; i < n - 1; i++) {
            cin >> x >> y;
            x--; y--;
            g[x].push_back(y);
            g[y].push_back(x);
        }

        dfs(0);

        int q;
        cin >> q;
        for (int i = 0; i < q; i++) {
            cin >> x >> y;
            x--; y--;
            cout << s(x) * s(y) << "\n";
        }

        for (int i = 0; i < n; i++) {
            dp[i] = -1;
            vis[i] = false;
            g[i].clear();
        }
    }

    return 0;
}
