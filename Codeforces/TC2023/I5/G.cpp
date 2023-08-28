#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define fst first
#define snd second
#define sz(x) ((int)x.size())
#define all(x) x.begin(),x.end()

using ll = long long;
using str = string;

const int MAXN = 1e5 + 10;
vector<ll> g[MAXN];
bool vis[MAXN];

void dfs(ll x) {
    vis[x] = true;
    for (auto e : g[x]) if (!vis[e]) dfs(e);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;
    vector<pair<ll, ll>> v(n);

    ll x, y;
    for (int i = 0; i < n; i++) {
        cin >> x;
        v[i] = {x, i};
    }
    sort(all(v));

    for (int i = 0; i < m; i++) {
        cin >> x >> y;
        x--; y--;
        g[x].pb(y);
        g[y].pb(x);
    }

    ll ans = 0;
    for (auto e : v) {
        if (!vis[e.snd]) {
            ans += e.fst;
            dfs(e.snd);
        }
    }
    cout << ans << "\n";

    return 0;
}
