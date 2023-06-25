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

const int MAXN = 1e5 + 10;
bool vis[MAXN];
vector<int> g[MAXN];
vector<pair<int, int>> cow;
int x_min, x_max, y_min, y_max;

void dfs(int i) {
    vis[i] = true;
    x_max = max(x_max, cow[i].first);
    x_min = min(x_min, cow[i].first);
    y_max = max(y_max, cow[i].second);
    y_min = min(y_min, cow[i].second);

    for (auto v : g[i]) {
        if (!vis[v]) {
            dfs(v);
        }
    }
}

int main() {
    setIO("fenceplan");
    int n, m;
    cin >> n >> m;
    

    int x, y;
    for (int i = 0; i < n; i++) {
        cin >> x >> y;
        cow.push_back({x, y});
    }

    for (int i = 0; i < m; i++) {
        cin >> x >> y;
        x--; y--;
        g[x].push_back(y);
        g[y].push_back(x);
    }

    int ans = 1e9;
    for (int i = 0; i < n; i++) {
        if (!vis[i]) {
            x_min = 1e9, x_max = 0, y_min = 1e9, y_max = 0;
            dfs(i);
            ans = min(ans, (x_max - x_min) * 2 + (y_max - y_min) * 2);
        }
    }

    cout << ans << "\n";
    return 0;
}
