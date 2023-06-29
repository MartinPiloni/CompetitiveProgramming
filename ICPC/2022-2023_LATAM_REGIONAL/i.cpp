#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using str = string;

#define sz(x) int((x).size())

vector<pair<int, int>> moves = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
const int MAXN = 1e2 + 10;
int grid[MAXN][MAXN];
vector<int> g[MAXN * MAXN];
bool vis[MAXN * MAXN];
int n, m;

bool valid(int i, int j, int v) {
    return (0 <= i && i < n && 0 <= j && j < m && grid[i][j] > v);
}

int bfs(int v) {
    int cnt = 0;

    queue<int> q;
    q.push(v);
    vis[v] = true;
    while(!q.empty()) {
        int p = q.front(); q.pop();
        cnt++;

        for (auto w : g[p]) {
            if (!vis[w]) {
                q.push(w);
                vis[w] = true;
            }
        }
    }

    return cnt;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> grid[i][j];
            grid[i][j]--;
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            for (auto move : moves) {
                if (valid(i + move.first, j + move.second, grid[i][j])) {
                    g[grid[i][j]].push_back(grid[i + move.first][j + move.second]);
                }
            }
        }
    }

    int ans = 0;
    for (int i = 0; i < n * m; i++) {
        ans = max(ans, bfs(i));
        memset(vis, 0, sizeof vis);
    }

    cout << ans << "\n";

   return 0;
}
