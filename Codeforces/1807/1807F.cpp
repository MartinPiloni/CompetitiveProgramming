#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define fst first
#define snd second
#define sz(x) ((int)x.size())
#define all(x) x.begin(),x.end()

using ll = long long;
using str = string;

bool ok = false;
bool cycle = false;
int ans = 0;
int n, m, ex, ey;
vector<vector<vector<vector<bool>>>> vis;

void dfs(int x, int y, int v, int h) {
    if (ok || cycle) return;

    if (vis[x][y][v][h]) {
        cycle = true;
        return;
    }

    if (x == ex && y == ey) {
        ok = true;
        return;
    }

    vis[x][y][v][h] = true;

    bool b = false;
    if (x == 0 && v == 1) {
        ans++;
        b = true;
        v = !v;
    } else if (x == n - 1 && v == 0) {
        ans++;
        b = true;
        v = !v;
    }

    if (y == 0 && h == 0) {
        if (!b) ans++;
        h = !h;
    } else if (y == m - 1 && h == 1) {
        if (!b) ans ++;
        h = !h;
    }

    if (v) x--;
    else x++;

    if (h) y++;
    else y--;

    dfs(x, y, v, h);
    return;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        int sx, sy;
        str dir;
        cin >> n >> m >> sx >> sy >> ex >> ey >> dir;
        sx--; sy--; ex--; ey--;

        vis.resize(n);
        for (int i = 0; i < n; i++) {
            vis[i].resize(m);
            for (int j = 0; j < m; j++) {
                vis[i][j].resize(2);
                for (int k = 0; k < 2; k++) {
                    vis[i][j][k].resize(2);
                }
            }
        }

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                for (int k = 0; k < 2; k++) {
                    for (int l = 0; l < 2; l++) {
                        vis[i][j][k][l] = false;
                    }
                }
            }
        }

        ok = false;
        cycle = false;
        ans = 0;
        int v, h;
        if (dir[0] == 'D') v = 0;
        else v = 1;

        if (dir[1] == 'L') h = 0;
        else h = 1;
        dfs(sx, sy, v, h);

        (ok ? cout << ans << "\n" : cout << "-1\n");
    }

    return 0;
}
