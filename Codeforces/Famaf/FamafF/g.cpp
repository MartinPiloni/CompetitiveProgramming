#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using str = string;

#define sz(x) int((x).size())

vector<pair<int, int>> moves = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
const int MAXN = 510;
vector<int> g[MAXN * MAXN];
vector<str> grid;
bool vis[MAXN * MAXN];
int n, m, k, cnt, emptys;

bool valid(int i, int j) {
    if (0 <= i && i < n && 0 <= j && j < m && grid[i][j] != '#') return true;
    else return false;
}

void dfs(int v) {
    if (cnt == emptys - k) return;
    vis[v] = true;
    cnt++;

    for (auto w : g[v]) {
        if (!vis[w]) dfs(w);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m >> k;

    str s;
    for (int i = 0; i < n; i++) {
        cin >> s;
        grid.push_back(s);
    }

    emptys = 0;
    int min_i = -1;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (grid[i][j] == '.') {
                if (min_i == -1) min_i = i * m + j;
                emptys++;
                for (auto move : moves) {
                    if (valid(i + move.first, j + move.second)) {
                        g[i * m + j].push_back((i + move.first) * m + (j + move.second));
                    }
                }
            } else {
                vis[i * m + j] = true;
            }
        }
    }

    cnt = 0;
    dfs(min_i);

    for (int i = 0; i < n * m; i++) {
        if (vis[i] == 0) {
            grid[i / m][i % m] = 'X';
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cout << grid[i][j];
        }
        cout << "\n";
    }

    return 0;
}
