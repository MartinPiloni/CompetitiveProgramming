#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using str = string;

#define sz(x) int((x).size())

const int MAXN = 1e5 + 10;
vector<pair<ll, ll>> g[MAXN];
bool vis[MAXN];
pair<ll, ll> dist[MAXN];
int n, m;

void dijkstra(ll x) {
    for (int i = 0; i < n; i++) dist[i].first = 1e18;
    dist[x].first = 0;
    dist[x].second = 0;

    priority_queue<pair<ll, ll>> q;
    q.push({0, x});
    while(!q.empty()) {
        ll a = q.top().second; q.pop();
        if (vis[a]) continue;
        vis[a] = true;
        for (auto u : g[a]) {
            ll b = u.first, w = u.second;
            if (dist[a].first + w < dist[b].first) {
                dist[b] = {dist[a].first + w, a};
                q.push({-dist[b].first, b});
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
        g[y].push_back({x, c});
    }

    dijkstra(0);
    if (dist[n - 1].first == (ll)1e18) {
        cout << -1 << "\n";
    } else { 
        vector<ll> ans = {n};

        ll j = n - 1;
        while(j != 0) {
            ans.push_back(dist[j].second + 1);
            j = dist[j].second;
        }

        for (int i = sz(ans) - 1; i >= 0; i--) {
            cout << ans[i] << " ";
        }
        cout << "\n";
    }

    return 0;
}
