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
      int n;
      cin >> n;

      vector<vector<ll>> g(n);
      int x, y;
      for (int i = 0; i < n - 1; i++) {
        cin >> x >> y;
        x--; y--;
        g[x].pb(y);
        g[y].pb(x);
      }

      vector<bool> vis(n);
      auto dfs = [&](ll cv, auto&& self) -> ll {
        vis[cv] = true;
        ll s = 0;

        if (sz(g[cv]) == 1) s += 3;
        else s += 2;

        for (auto e : g[cv]) {
          if (!vis[e]) {
            s += self(e, self);
          }
        }

        return s;
      };
      cout << dfs(0, dfs) << "\n";
    }
  return 0;
}
