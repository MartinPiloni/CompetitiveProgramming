#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(int i=a;i<b;++i)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))

using ll = long long;
using str = string;

vector<pair<int, int>> moves = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
const int MAXN = 50 * 50 + 10;
vector<int> g[MAXN * MAXN];
int comp[MAXN * MAXN];
bool vis[MAXN * MAXN];
str grid[60];
int n, x_s, y_s, x_t, y_t;

bool valid(int x, int y) {
    return (0 <= x && x < n && 0 <= y && y < n && grid[x][y] == '0');
}

void dfs(int v, int c) {
    vis[v] = true;
    comp[v] = c;

    for (auto w : g[v]) {
        if(!vis[w]) {
            dfs(w, c);
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;
    cin >> x_s >> y_s >> x_t >> y_t;
    x_s--; y_s--; x_t--; y_t--;

    fore(i, 0, n) cin >> grid[i];

    fore(i, 0, n) fore(j, 0, n) {
        for(auto move : moves) {
            if(grid[i][j] != '1' && valid(i + move.fst, j + move.snd)) {
                g[i * n + j].pb((i + move.fst) * n + (j + move.snd));
            }
        }
    }

    int c = 1;
    dfs(x_s * n + y_s, c);
    c++;
    if (!vis[x_t * n + y_t]) dfs(x_t * n + y_t, c);

    ll ans = (ll)1e18;
    for (ll i = 0; i < n * n; i++) {
        for (ll j = i + 1; j < n * n; j++) {
            if((comp[i] == 1 && comp[j] == 2) || (comp[i] == 2 && comp[j] == 1)) {
                ans = min(ans, (((i / n) + 1) - ((j / n) + 1)) * (((i / n) + 1) - ((j / n) + 1)) + (((i % n) + 1) - ((j % n) + 1)) * (((i % n) + 1) - ((j % n) + 1)));
            }
        }
    }

    (ans == (ll)1e18 ? cout << "0\n" : cout << ans << "\n");
    return 0;
}
