#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(int i=a,ggdem=b;i<ggdem;++i)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))

using ll = long long;
using str = string;

const int MAXN = 2e3 + 10;
vector<ll> g[MAXN];
bool vis[MAXN];
ll dist[MAXN];

void bfs(ll v) {
    queue<ll> q;
    q.push(v);
    dist[v] = 0;
    vis[v] = true;
    while (!q.empty()) {
        ll p = q.front(); q.pop();
        for (auto w : g[p]) {
            if (!vis[w]) {
                q.push(w);
                vis[w] = true;
                dist[w] = dist[p] + 1;
            }
        }
    }
    
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    
    ll p;
    vector<ll> roots;
    fore(i, 0, n) {
        cin >> p;
        p--;
        if (p < 0) roots.pb(i);
        if (p >= 0) g[p].pb(i);
    }

    for (auto root : roots) {
        bfs(root);
    }

    ll ans = 0;
    fore(i, 0, n) ans = max(ans, dist[i] + 1);

    cout << ans << "\n";
    return 0;
}
