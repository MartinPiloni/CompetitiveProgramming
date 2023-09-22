#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define fst first
#define snd second
#define sz(x) ((int)x.size())
#define all(x) x.begin(),x.end()

using ll = long long;
using str = string;

const int MAXN = 2e5 + 10;
vector<int> g[MAXN];
int par[MAXN];
bool vis[MAXN];
int n, s_c, e_c;

void dfs(int x, int p) {
    vis[x] = true;
    par[x] = p;
    for (auto e : g[x]) {
        if (!vis[e]) dfs(e, x);
        else if (s_c == -1 && p != -1 && e != p) {
            s_c = e; 
            e_c = x;
        }
    }
}

vector<int> bfs(int x) {
    vector<int> dist(n);
    queue<int> q;
    q.push(x);
    dist[x] = 0;
    vis[x] = true;
    while (!q.empty()) {
        auto v = q.front(); q.pop();
        for (auto e : g[v]) {
            if (!vis[e]) {
                q.push(e);
                vis[e] = true;
                dist[e] = dist[v] + 1;
            }
        }
    }
    return dist;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        int a, b;
        cin >> n >> a >> b;
        a--; b--;

        int x, y;
        for (int i = 0; i < n; i++) {
            cin >> x >> y;
            x--; y--;
            g[x].pb(y);
            g[y].pb(x);
        }

        s_c = -1;
        dfs(b, -1);
        memset(vis, 0, sizeof vis);
        vector<int> d_m = bfs(a);
        memset(vis, 0, sizeof vis);
        vector<int> d_v = bfs(b);

        vector<int> cycle;
        int v = e_c;
        cycle.pb(e_c);
        while (v != s_c) {
            v = par[v];
            cycle.pb(v);
        }

        int mini = 0, min_d = 1e9;
        for (auto e : cycle) {
            if (d_v[e] < min_d) {
                mini = e;
            }
        }

        if (d_v[mini] < d_m[mini]) {
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }

        for (int i = 0; i < n; i++) {
            g[i].clear();
            vis[i] = false;
            par[i] = 0;
        }
    }

    return 0;
}
