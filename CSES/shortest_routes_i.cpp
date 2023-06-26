#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using str = string;

#define sz(x) int((x).size())

const int MAXN = 1e5 + 10;
vector<pair<ll, ll>> g[MAXN];
bool vis[MAXN];
ll dist[MAXN];
int n, m;

void dijkstra(ll x) {
    for (int i = 0; i < n; i++) dist[i] = 1e18;
    dist[x] = 0;

    priority_queue<pair<ll, ll>> q;
    q.push({0, x});
    while(!q.empty()) {
        ll a = q.top().second; q.pop();
        if (vis[a]) continue;
        vis[a] = true;
        for (auto u : g[a]) {
            ll b = u.first, w = u.second;
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

    cin >> n >> m;

    ll x, y, c;
    for (int i = 0; i < m; i++) {
        cin >> x >> y >> c;
        x--; y--;
        g[x].push_back({y, c});
    }

    dijkstra(0);
    for (int i = 0; i < n; i++) {
        cout << dist[i] << " \n"[i == n-1];
    }

    return 0;
}
