#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define fst first
#define snd second
#define sz(x) ((int)x.size())
#define all(x) x.begin(),x.end()

using ll = long long;
using str = string;

const int MAXN = 3e5 + 10;
vector<int> g[MAXN];
vector<ll> size_st;
int p[MAXN];
bool vis[MAXN];

ll dfs(int x) {
    vis[x] = true;
    ll cnt = 1;
    for (auto e : g[x]) {
        if (!vis[e]) {
            p[e] = x;
            cnt += dfs(e);
        }
    }
    size_st[x] = cnt;

    return cnt;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, x, y;
    cin >> n >> x >> y;
    x--; y--;
    
    int a, b;
    for (int i = 0; i < n - 1; i++) {
        cin >> a >> b;
        a--; b--;
        g[a].pb(b);
        g[b].pb(a);
    }
    size_st.resize(n);
    dfs(x);

    ll cnt = 0, r = y;
    while (p[r] != x) {
        cnt++;
        r = p[r];
    }

    ll ans = 0;
    ans = size_st[r] * (n - 1);
    for (auto e : g[x]) {
        if (e != r) {
            ans += size_st[e] * (n - 1 - size_st[y]); 
        }
    }
    ans += n - 1 - size_st[y];
    cout << ans << "\n";

    return 0;
}
