#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using str = string;

#define sz(x) int((x).size())

const int MAXN = 1e4 + 10;
vector<pair<int, int>> g[MAXN];
bool vis[MAXN];
int dist[MAXN];
int n, m;

void dijkstra(int x) {
    for (int i = 0; i < n; i++) dist[i] = 1e9;
    dist[x] = 0;

    priority_queue<pair<int, int>> q;
    q.push({0, x});
    while(!q.empty()) {
        int a = q.top().second; q.pop();
        if (vis[a]) continue;
        vis[a] = true;
        for (auto u : g[a]) {
            int b = u.first, w = u.second;
            if (dist[a] + w < dist[b]) {
                dist[b] = dist[a] + w;
                q.push({-dist[b], b});
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while(t--) {
        cin >> n >> m;

        int x, y, c;
        for (int i = 0; i < m; i++) {
            cin >> x >> y >> c;
            x--; y--;
            g[x].push_back({y, c});
        }

        cin >> x >> y;
        x--; y--;
        dijkstra(x);

        (dist[y] == (int)1e9 ? cout << "NO\n" : cout << dist[y] << "\n");

        for (int i = 0; i < n; i++) {
            g[i].clear();
            dist[i] = 0;
            vis[i] = 0;
        }
    }

    return 0;
}
