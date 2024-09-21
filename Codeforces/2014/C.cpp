#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define fst first
#define snd second
#define int long long
#define sz(x) ((int)x.size())
#define all(x) x.begin(),x.end()
#define dbg(x) cerr << #x << ": " << (x) << endl

using ll = long long;
using ld = long double;
using str = string;

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
      int n;
      cin >> n;
      vector<ll> v(n);
      ld avg_sum = 0;
      for (int i = 0; i < n; i++) {
        cin >> v[i];
        avg_sum += v[i];
      }
      sort(all(v));

      if (n <= 2) {
        cout << "-1\n";
        continue;
      }

      auto can = [&](ll m) {
        ld aux = avg_sum - v[n - 1];
        aux += v[n - 1] + m;
        aux /= n;
        if (aux / 2 > v[n / 2]) return true;
        else return false;
      };

      ll l = 0, r = 1e18, m;
      while (l <= r) {
        m = (l + r) / 2;
        if (can(m)) r = m - 1;
        else l = m + 1;
      }
      cout << r + 1 << "\n";
    }

    return 0;
}
