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

const int MAXN = 2e5 + 10;
vector<int> g[MAXN];
bool vis[MAXN];

bool dfs(int v) {
    bool ans = (SZ(g[v]) == 2);
    vis[v] = true;
    for (auto w : g[v]) {
        if (!vis[w]) {
            ans &= dfs(w);
        }
    }

    return ans;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    int x, y;
    fore(i, 0, m) {
        cin >> x >> y;
        x--; y--;
        g[x].pb(y);
        g[y].pb(x);
    }

    int ans = 0;
    fore(i, 0, n) {
        if (!vis[i]) {
            if (dfs(i)) ans++;
        }
    }

    cout << ans << "\n";

    return 0;
}
