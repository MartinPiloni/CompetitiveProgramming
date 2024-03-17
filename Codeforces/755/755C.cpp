#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define fst first
#define snd second
#define sz(x) ((int)x.size())
#define all(x) x.begin(),x.end()

using ll = long long;
using str = string;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<vector<int>> g(n + 10);
    vector<bool> vis(n + 10);

    int x;
    for (int i = 0; i < n; i++) {
        cin >> x;
        x--;
        g[i].pb(x);
        g[x].pb(i);
    }

    auto dfs = [&](auto&& dfs, int v) -> void {
        vis[v] = 1;
        for (auto e : g[v]) if(!vis[e]) dfs(dfs, e);
    };

    int comps = 0;
    for (int i = 0; i < n; i++) {
        if (!vis[i]) {
            comps++;
            dfs(dfs, i);
        }
    }
    cout << comps << "\n";

    return 0;
}
