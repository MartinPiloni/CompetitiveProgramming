#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define fst first
#define snd second
#define sz(x) ((int)x.size())
#define all(x) x.begin(),x.end()

using ll = long long;
using str = string;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;
    vector<str> g(n);
    for (int i = 0; i < n; i++) cin >> g[i];

    auto check_a = [&](int x, int y) -> bool {
      return (g[x - 2][y + 1] == '#' && g[x][y + 2] == '#');
    };

    auto check_p = [&](int x, int y) -> bool {
      return (g[x - 2][y + 1] == '#');
    };

    auto erase_t = [&](int x, int y) {
      for (int i = x; i >= x - 4; i--) g[i][y] = '.';
      x -= 4;
      y--;
      for (int i = y; i < y + 3; i++) g[x][i] = '.';
    };

    auto erase_p = [&](int x, int y) {
      for (int i = x; i >= x - 4; i--) g[i][y] = '.';
      x -= 4;
      y++;
      for (int i = y; i < y + 2; i++) {
        g[x][i] = '.';
        g[x + 2][i] = '.';
      }
      g[x + 1][y + 1] = '.';
    };

    auto erase_a = [&](int x, int y) {
      g[x][y + 2] = '.';
      g[x - 1][y + 2] = '.';
    };

    ll ans_t = 0, ans_a = 0, ans_p = 0;
    for (int i = n - 1; i >= 0; i--) {
      for (int j = 0; j < m; j++) {
        if (g[i][j] == '#') {
          if (g[i][j] == '#' && check_a(i, j)) {
            ans_a++;
            erase_p(i, j);
            erase_a(i, j);
          } else if (g[i][j] == '#' && check_p(i, j)) {
            ans_p++;
            erase_p(i, j);
          } else if (g[i][j] == '#') {
            ans_t++;
            erase_t(i, j);
          }
        }
      }
    }
    cout << ans_t << " " << ans_a << " " << ans_p << "\n";

    return 0;
}
