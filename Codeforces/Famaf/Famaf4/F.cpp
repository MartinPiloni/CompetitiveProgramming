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

const int MAXN = 1e5 + 10;
pair<ll, ll> v[MAXN];
vector<int> g[MAXN];
int p[MAXN];
ll dp[MAXN][2];
int n;

void build_parents(int x) {
    for (auto w : g[x]) {
        if (p[w] == -1) {
            p[w] = x;
            build_parents(w);
        }
    }
}

ll f(ll x, int c) {
    if (x == n) return 0;

    ll &r = dp[x][c];
    if (r != -1) return r;

    r = 0;
    if (c == 0) {
        for (auto w : g[x]) {
            if (p[x] == w) continue;
            r += max(abs(v[x].fst - v[w].fst) + f(w, 0), abs(v[x].fst - v[w].snd) + f(w, 1));
        }
    } else {
        for (auto w : g[x]) {
            if (p[x] == w) continue;
            r += max(abs(v[x].snd - v[w].fst) + f(w, 0), abs(v[x].snd - v[w].snd) + f(w, 1));
        }
    }
    
    return r;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        memset(dp, -1, sizeof dp);
        memset(p, -1, sizeof p);

        cin >> n;
        ll l, r;
        fore(i, 0, n) {
            cin >> l >> r;
            v[i] = {l, r};
        }

        int x, y;
        fore(i, 0, n - 1) {
            cin >> x >> y;
            x--; y--;
            g[x].pb(y);
            g[y].pb(x);
        }

        p[0] = 0;
        build_parents(0);
        cout << max(f(0, 0), f(0, 1)) << "\n";

        fore(i, 0, n) {
            g[i].clear();
        }
    }

    return 0;
}
