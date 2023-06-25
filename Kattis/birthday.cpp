#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using str = string;

#define sz(x) int((x).size())

const int MAXN = 1e2 + 10;
bool g[MAXN][MAXN];
bool vis[MAXN];
int p, c;

void dfs(int v) {
    vis[v] = true;

    for (int i = 0; i < p; i++) {
        if (!vis[i] && g[v][i]) {
            dfs(i);
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    while(1) {
        cin >> p >> c;

        if (p == 0 && c == 0) break;

        int x, y;
        vector<pair<int, int>> edges;
        for (int i = 0; i < c; i++) {
            cin >> x >> y;
            g[x][y] = true;
            g[y][x] = true;
            edges.push_back({x, y});
        }

        bool f = true;
        for (auto edge : edges) {
            g[edge.first][edge.second] = false;
            g[edge.second][edge.first] = false;

            dfs(0);
            for (int i = 0; i < p; i++) {
                if (!vis[i]) {
                    f = false;
                    break;
                }
            }

            g[edge.first][edge.second] = true;
            g[edge.second][edge.first] = true;

            for (int i = 0; i < p; i++) {
                vis[i] = false;
            }
        }

        (f ? cout << "No\n" : cout << "Yes\n");

        for (int i = 0; i < p; i++) {
            memset(g[i], 0, sizeof(g[i]));
        }
    }

    return 0;
}
