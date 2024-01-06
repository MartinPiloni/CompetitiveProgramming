#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define fst first
#define snd second
#define sz(x) ((int)x.size())
#define all(x) x.begin(),x.end()

using ll = long long;
using str = string;

vector<int> dx = {1, 0, -1, 0};
vector<int> dy = {0, 1, 0, -1};
const int MAXN = 1e3 + 10;
str g[MAXN];
bool vis[MAXN][MAXN][4][4];
bool ok = false;
int n, m, s_x, s_y, e_x, e_y;

bool valid(int x, int y) {
    return (x >= 0 && x < n && y >= 0 && y < m && g[x][y] != '*');
}

void dfs(int x, int y, int t, int dir) {
    if (ok || t > 2) return;
    if (x == e_x && y == e_y && t <= 2) ok = true;
    vis[x][y][t][dir] = true;


    //cout << "x: " << x << " y: " << y << " turns: " << t << " dir: " << dir << endl;
    int turns;
    for (int i = 0; i < 4; i++) {
        if (!valid(x + dx[i], y + dy[i])) continue;

        if (((dir == 0 || dir == 2) && (i != 0 && i != 2)) || ((dir == 1 || dir == 3) && (i != 1 && i != 3))) turns = t + 1;
        else turns = t;

        if (!vis[x + dx[i]][y + dy[i]][turns][i]) dfs(x + dx[i], y + dy[i], turns, i);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m;
    for (int i = 0; i < n; i++) cin >> g[i];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (g[i][j] == 'S') {
                s_x = i;
                s_y = j;
            } else if (g[i][j] == 'T') {
                e_x = i;
                e_y = j;
            }
        }
    }


    for (int i = 0; i < 4; i++) {
        if (valid(s_x + dx[i], s_y + dy[i])) dfs(s_x + dx[i], s_y + dy[i], 0, i);
    }
    (ok ? cout << "YES\n" : cout << "NO\n");
    return 0;
}
