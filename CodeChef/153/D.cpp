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
      vector<int> v(n);
      for (int i = 0; i < n; i++) cin >> v[i];

      ll ans = 0;
      for (int i = 0; i < n; i++) {
        if (v[i] > i + 1) ans = max(ans, v[i] + 1);
      }
      cout << ans << "\n";
    }

    return 0;
}
