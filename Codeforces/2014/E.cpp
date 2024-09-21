#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define fst first
#define snd second
#define int long long
#define sz(x) ((int)x.size())
#define all(x) x.begin(),x.end()
#define dbg(x) cerr << #x << ": " << (x) << endl

using ll = long long;
using str = string;

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
      int n, m, h;
      cin >> n >> m >> h;

      vector<vector<pair<ll, ll>>> g(2 * n);
      ll x;
      for (int i = 0; i < h; i++) {
        cin >> x;
        x--;
        g[x].pb({x + n, 0});
      }

      ll y, cost;
      for (int i = 0; i < m; i++) {
        cin >> x >> y >> cost;
        x--; y--;
        g[x].pb({y, cost});
        g[y].pb({x, cost});
        g[x + n].pb({y + n, cost / 2});
        g[y + n].pb({x + n, cost / 2});
      }

      auto dijkstra = [&](ll v) {
        vector<ll> dist(2 * n, 1e18);
        vector<ll> vis(2 * n);
        priority_queue<pair<ll, ll>> pq;
        pq.push({0, v});
        dist[v] = 0;
        while (!pq.empty()) {
          ll cv = pq.top().snd;
          pq.pop();

          if (vis[cv]) continue;
          vis[cv] = true;

          for (auto e : g[cv]) {
            ll cn = e.fst;
            ll cc = e.snd;

            if (dist[cv] + cc < dist[cn]) {
              dist[cn] = dist[cv] + cc;
              pq.push({-dist[cn], cn});
            }
          }
        }

        for (int i = 0 ; i < n; i++) dist[i] = min(dist[i], dist[i + n]);
        return dist;
      };

      vector<ll> marian = dijkstra(0);
      vector<ll> robin = dijkstra(n - 1);
      ll ans = 1e18;
      for (int i = 0; i < n; i++) {
        ans = min(ans, max(marian[i], robin[i]));
      }
      if (ans == (ll)1e18) {
        cout << "-1\n";
        continue;
      }
      cout << ans << "\n";
    }

    return 0;
}
