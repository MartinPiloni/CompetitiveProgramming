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

const int MAXN = 3010;
vector<int> g[MAXN];
bool vis[MAXN];

void dfs(int v) {
    if (vis[v]) return;

    vis[v] = true;
    for (auto p : g[v]) {
        dfs(p);
    }
}

int main() {
    setIO("closing");

    int n, m;
    cin >> n >> m;

    int x, y;
    for (int i = 0; i < m; i++) {
        cin >> x >> y;
        x--; y--;
        g[x].push_back(y);
        g[y].push_back(x);
    }

    vector<int> v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
        v[i]--;
    }
    
    for (int i = 0; i < n; i++) {
        int c = 0; 
        for (int j = 0; j < n; j++) {
            if (!vis[j]) {
                c++;
                dfs(j);
            }
        }

        (c == 1 ? cout << "YES\n" : cout << "NO\n");
        for (int j = 0; j < n; j++) {
            vis[j] = false;
        }

        for (int j = 0; j <= i; j++) {
            vis[v[j]] = true;
        }
    }

    return 0;
}
