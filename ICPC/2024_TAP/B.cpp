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

    int n;
    cin >> n;
    
    auto get_divs = [&](ll x) {
      vector<ll> ans;
      for (int i = 1; i * i <= x; i++) {
        if (x % i == 0) {
          ans.pb(i);
          if (x / i != i) ans.pb(x / i);
        }
      }
      return ans;
    };

    auto divs = get_divs(n);
    sort(all(divs));
    reverse(all(divs));

    vector<ll> ans;
    for (int i = 1; i < sz(divs); i++) {
      bool ok = true;
      for (int j = 1; j < i; j++) {
        if (divs[j] % divs[i] == 0)  {
          ok = false;
          break;
        };
      }
      if (ok) ans.pb(divs[i]);
    }

    cout << sz(ans) << "\n";
    for (auto e : ans) cout << "1 " << e << "\n";

    return 0;
}
