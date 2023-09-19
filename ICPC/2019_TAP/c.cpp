#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define fst first
#define snd second
#define sz(x) ((int)x.size())
#define all(x) x.begin(),x.end()

using ll = long long;
using str = string;

const int MAXN = 2e3 + 10;
str v[MAXN];
vector<int> dx = {1, 0, -1, 0};
vector<int> dy = {0, 1, 0, -1};
int h, w;

bool valid(int x, int y) {
    int cnt_r = 0, cnt_l = 0, cnt_u = 0, cnt_b = 0;

    int i = 1;
    while (x + i < h && v[x + i][y] == '*') {
        if (v[x + i][y + 1] == '*' || v[x + i][y - 1] == '*') return false;
        cnt_b++;
        i++;
    }

    i = 1;
    while (x - i >= 0 && v[x - i][y] == '*') {
        if (v[x - i][y + 1] == '*' || v[x - i][y - 1] == '*') return false;
        cnt_u++;
        i++;
    }

    i = 1;
    while (y - i >= 0 && v[x][y - i] == '*') {
        if (v[x + 1][y - i] == '*' || v[x - 1][y - i] == '*') return false;
        cnt_l++;
        i++;
    }

    i = 1;
    while (y + i < w && v[x][y + i] == '*') {
        if (v[x + 1][y + i] == '*' || v[x - 1][y + i] == '*') return false;
        cnt_r++;
        i++;
    }

    return (cnt_r == cnt_l && cnt_l == cnt_u && cnt_b > cnt_u);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> h >> w;
    for (int i = 0; i < h; i++) cin >> v[i];

    int ans = 0;
    for (int i = 1; i < h - 2; i++) {
        for (int j = 1; j < w - 1; j++) {
            if (v[i][j] == '*') {
                bool f = true;
                for (int k = 0; k < 4; k++) {
                    if (v[i + dx[k]][j + dy[k]] != '*') {f = false; break;}
                }

                if (f) ans += valid(i, j);
            }
        }
    }
    
    cout << ans << "\n";
    return 0;
}
