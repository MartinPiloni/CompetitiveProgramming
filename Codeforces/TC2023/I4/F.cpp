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
vector<int> g[MAXN];
int color[MAXN];
bool vis[MAXN];
ll cnt0, cnt1;

void dfs(int x, int c) {
    vis[x] = true;
    color[x] = c;
    (c == 0 ? cnt0++ : cnt1++);
    for (auto e : g[x]) if(!vis[e]) dfs(e, !c);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    int x, y;
    for (int i = 0; i < n - 1; i++) {
        cin >> x >> y;
        x--; y--;
        g[x].pb(y);
        g[y].pb(x);
    }

    cnt0 = 0; cnt1 = 0;
    dfs(0, 0);

    ll ans = 0;
    for (int i = 0; i < n; i++) {
        if (color[i] == 0) ans += cnt1 - sz(g[i]);
        else ans += cnt0 - sz(g[i]);
    }
    cout << ans / 2 << "\n";

    return 0;
}
