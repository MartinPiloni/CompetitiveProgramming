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
      for (int i = 0; i < n; i++) {
        cin >> v[i];
      }

      ll s = 0, mini = 1e18;
      for (int i = 0; i < n; i++) {
        s += v[i];
        mini = min(mini, s / (i + 1));
      }

      auto ceil = [&](ll x, ll y) {
        return (x + y - 1) / y;
      };

      s = 0;
      ll maxi = 0;
      for (int i = n - 1; i >= 0; i--) {
        s += v[i];
        maxi = max(maxi, ceil(s, n - i));
      }
      cout << maxi - mini << "\n";
    }

    return 0;
}
