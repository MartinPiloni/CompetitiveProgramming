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

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
      ll n, m, q;
      cin >> n >> m >> q;
      vector<ll> v(m);
      for (int i = 0; i < m; i++) cin >> v[i];
      sort(all(v));

      auto ceil = [&](ll a, ll b) {
          return (a + b - 1) / b;
      };

      ll x;
      while(q--) {
        cin >> x;
        if (x < v[0]) cout << v[0] - 1 << "\n";
        else if (x > v[m - 1]) cout << n - v[m - 1] << "\n";
        else {
          auto it = lower_bound(all(v), x);
          auto it2 = it;
          it2--;
          cout << ceil((*it - *it2 - 1), 2) << "\n";
        }
      }
    }

    return 0;
}
