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

const int MAXN = 5e2 + 10;
vector<pair<int, int>> moves = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
str grid[MAXN];
vector<int> g[MAXN * MAXN];
bool vis[MAXN * MAXN];
map<char, char> n_c;
int n, m;

void dfs(int v) {
    vis[v] = true;

    for (auto w : g[v]) {
        if (!vis[w]) dfs(w);
    }
}

bool valid(int i, int j) {
    return (0 <= i && i < n && 0 <= j && j < m);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    n_c['s'] = 'n';
    n_c['n'] = 'u';
    n_c['u'] = 'k';
    n_c['k'] = 'e';
    n_c['e'] = 's';

    cin >> n >> m;
    fore(i, 0, n) cin >> grid[i];
    fore(i, 0, n) {
        for (int j = 0; j < m; j++) {
            for (auto move : moves) {
                if (valid(i + move.fst, j + move.snd) && n_c[grid[i][j]] == grid[i + move.fst][j + move.snd]) {
                    g[i * m + j].pb((i + move.fst) * m + j + move.snd);
                }
            }
        }
    }

    dfs(0);
    (vis[n * m - 1] ? cout << "Yes\n" : cout << "No\n");

    return 0;
}
