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

    int t;
    cin >> t;
    while (t--) {
      int n;
      cin >> n;
      vector<ll> ps(n + 1);
      vector<ll> v(n);
      for (int i = 0; i < n; i++) {
         cin >> v[i];
         ps[i + 1] = ps[i] + v[i];
      }

      str s;
      cin >> s;

      vector<int> l_ind, r_ind;
      for (int i = 0; i < n; i++) {
        if (s[i] == 'L') l_ind.pb(i);
        if (s[n - 1 - i] == 'R') r_ind.pb(n - 1 - i);
      }

      ll ans = 0;
      for (int i = 0; i < min(sz(l_ind), sz(r_ind)); i++) {
        if (l_ind[i] < r_ind[i]) {
          ans += ps[r_ind[i] + 1] - ps[l_ind[i]];
        }
      }
      cout << ans << "\n";
    }

    return 0;
}
