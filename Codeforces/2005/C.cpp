#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define fst first
#define snd second
#define sz(x) ((int)x.size())
#define all(x) x.begin(),x.end()
#define dbg(x) cerr << #x << ": " << (x) << endl

using ll = long long;
using str = string;

const int INF = 1e9;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    str narek = "narek";
    set<char> se = {'n', 'a', 'r', 'e', 'k'};

    int t;
    cin >> t;
    while (t--) {
      int n, m;
      cin >> n >> m;

      str s = "";
      str aux;
      for (int i = 0; i < n; i++) {
        cin >> aux;
        s += aux;
      }

      vector<vector<ll>> dp(n * m, vector<ll>(5, -INF));
      auto f = [&](ll pos, ll c, auto&& f) -> ll {
        if (pos >= n * m) return -c;

        ll &res = dp[pos][c];
        if (res != -INF) return res;

        res = 0;
        if (pos % m == 0) {
          if (s[pos] == narek[c] && c == 4) {
            res = max(f(pos + m, c, f), 5 + f(pos + 1, 0, f));
          } else if (s[pos] == narek[c]) {
            res = max(f(pos + m, c, f), f(pos + 1, c + 1, f));
          } else if (se.count(s[pos])) {
            res = max(f(pos + m, c, f), f(pos + 1, c, f) - 1);
          } else {
            res = max(f(pos + m, c, f), f(pos + 1, c, f));
          }
        } else {
          if (s[pos] == narek[c] && c == 4) {
            res = 5 + f(pos + 1, 0, f);
          } else if (s[pos] == narek[c]) {
            res = f(pos + 1, c + 1, f);
          } else if (se.count(s[pos])) {
            res = f(pos + 1, c, f) - 1;
          } else {
            res = f(pos + 1, c, f);
          }
        }

        return res;
      };
      cout << max(0LL, f(0, 0, f)) << "\n";
    }

    return 0;
}
