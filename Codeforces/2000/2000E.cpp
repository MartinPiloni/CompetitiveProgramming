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
      ll n, m, k;
      cin >> n >> m >> k;

      ll w;
      cin >> w;
      vector<ll> v(w);
      for (int i = 0; i < w; i++) {
        cin >> v[i];
      }
      sort(all(v));
      reverse(all(v));
      

      vector<ll> squares(n * m + 10);
      for (ll i = 0; i < n; i++) {
        ll cnt_r, cnt_c;
        for (ll j = 0; j < m; j++) {
          cnt_r = min({i + 1, n - i, k, n - k + 1});
          cnt_c = min({j + 1, m - j, k, m - k + 1});
          squares[i * m + j] = cnt_c * cnt_r;
        }
      }
      sort(all(squares));
      reverse(all(squares));


      ll ans = 0;
      for (int i = 0; i < sz(v); i++) {
        ans += v[i] * squares[i];
      }
      cout << ans << "\n";
    }

    return 0;
}
