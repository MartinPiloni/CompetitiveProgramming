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
int n, m, p, r;
vector<pair<int, ll>> g[MAXN];
ll dist[MAXN];

void dijkstra(int x) {
    memset(dist, -1, sizeof dist);
    priority_queue<pair<ll, int>> q;
    dist[x] = 0; q.push({0, x});
    while(!q.empty()) {
        x = q.top().snd; ll c = -q.top().fst; q.pop();
        if(dist[x] != c) continue;
        for (int i = 0; i < sz(g[x]); i++) {
            int y = g[x][i].fst; c = g[x][i].snd;
            if (dist[y] < 0 || dist[x] + c < dist[y]) {
                dist[y] = dist[x] + c, q.push({-dist[y], y});
            }
        }
    }

}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m >> p >> r;
    p--; r--;

    int u, v, d;
    for (int i = 0; i < m; i++) {
        cin >> u >> v >> d;
        u--; v--;
        g[u].pb({v, d});
        g[v].pb({u, d});
    }

    dijkstra(p);

    ll dist_r = dist[r];
    vector<ll> candidates;
    for (int i = 0; i < n; i++) {
        if (dist[i] == dist[r] * 2) {
            candidates.pb(i);
        }
    }

    if (sz(candidates) == 0) {
        cout << "*\n";
        return 0;
    }

    for (int i = 0; i < sz(g[r]); i++) {
        g[r][i].snd = 1e18;
    }
    dijkstra(p);

    sort(all(candidates));

    bool f = false;
    for (int i = 0; i < sz(candidates); i++) {
        if (dist[candidates[i]] == dist_r * 2) {
            continue;
        } else {
            f = true;
            cout << candidates[i] + 1 << " ";
        }
    }
    if (!f) cout << "*";
    cout << "\n";
    

    return 0;
}