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
bool g[MAXN][MAXN][4]; // left, up, right, down
int comp[MAXN][MAXN];
vector<int> dx = {-1, 0, 1, 0};
vector<int> dy = {0, 1, 0, -1};

bool valid(int x, int y) {
    return (x >= 0 && x < MAXN && y >= 0 && y < MAXN);
}

void dfs(int x, int y, int c) {
    comp[x][y] = c;

    for (int i = 0; i < 4; i++) {
        if (valid(x + dx[i], y + dy[i]) && comp[x + dx[i]][y + dy[i]] == 0 && g[x][y][i]) {
            dfs(x + dx[i], y + dy[i], c);
        }
    }
} 

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    memset(g, true, sizeof g);

    int l_x, l_y, x, y;
    cin >> l_x >> l_y;

    for (int i = 0; i < n; i++) {
        cin >> x >> y;

        if (l_x != x) {
            for (int j = min(x, l_x); j < max(x, l_x); j++) {
                g[j][y][3] = false;
                g[j][y - 1][1] = false;
            }
        } else {
            for (int j = min(y, l_y); j < max(y, l_y); j++) {
                g[x][j][0] = false;
                g[x - 1][j][2] = false;
            }
        }

        l_x = x;
        l_y = y;
    }

    dfs(0, 0, 1);

    int c = 2;
    for (int i = 0; i < MAXN; i++) {
        for (int j = 0; j < MAXN; j++) {
            if (comp[i][j] == 0) {
               dfs(i, j, c);
               c++;
            }
        }
    }

    vector<int> area(1e6 + 10);
    int ans = 0;
    for (int i = 0; i < MAXN; i++) {
        for (int j = 0; j < MAXN; j++) {
            if (comp[i][j] != 1) {
                area[comp[i][j]]++;
                ans = max(ans, area[comp[i][j]]);
            }
        }
    }
    cout << ans << "\n";

    return 0;
}
