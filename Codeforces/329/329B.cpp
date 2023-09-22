#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define fst first
#define snd second
#define sz(x) ((int)x.size())
#define all(x) x.begin(),x.end()

using ll = long long;
using str = string;

const int MAXN = 1e3 + 10;
vector<int> dx = {1, 0, -1, 0};
vector<int> dy = {0, 1, 0, -1};
bool g[MAXN][MAXN][4]; 
bool vis[MAXN][MAXN];
int d[MAXN][MAXN];
int n, m;

bool valid(int x, int y) {
    return (x >= 0 && y >= 0 && x < n && y < m);
}

void bfs(int x, int y) {
    queue<pair<int, int>> q;
    q.push({x, y});
    vis[x][y] = true;
    d[x][y] = 0;
    while (!q.empty()) {
        auto p = q.front(); q.pop();
        for (int i = 0; i < 4; i++) {
            if (g[p.fst][p.snd][i] && !vis[p.fst + dx[i]][p.snd + dy[i]]) {
                q.push({p.fst + dx[i], p.snd + dy[i]});
                vis[p.fst + dx[i]][p.snd + dy[i]] = true;
                d[p.fst + dx[i]][p.snd + dy[i]] = d[p.fst][p.snd] + 1;
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m;
    vector<str> grid(n);
    for (int i = 0; i < n; i++) {
        cin >> grid[i];
    }

    pair<int, int> s, e;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            d[i][j] = 1e9;
            if (grid[i][j] == 'S') s = {i, j};
            if (grid[i][j] == 'E') e = {i, j};
            if (grid[i][j] == 'T') continue;

            for (int k = 0; k < 4; k++) {
                if (valid(i + dx[k], j + dy[k]) && grid[i + dx[k]][j + dy[k]] != 'T') {
                    g[i][j][k] = true;
                }
            }
        }
    }
    
    bfs(e.fst, e.snd);
    ll ans = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (grid[i][j] >= '0' && grid[i][j] <= '9' && d[i][j] <= d[s.fst][s.snd]) {
                ans += grid[i][j] - '0';
            }
        }
    }
    cout << ans << "\n";

    return 0;
}
