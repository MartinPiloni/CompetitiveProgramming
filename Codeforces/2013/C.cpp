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

      str ans = "";
      int ok;
      bool f = false;
      while (sz(ans) < n) {
        if (!f) {
          cout << "? " << ans + '0' << endl;
          cin >> ok;

          if (ok) ans += '0';
          else {
            cout << "? " << ans + '1' << endl;
            cin >> ok;
            if (ok) {
              ans += '1';
            } else {
              f = true;
            }
          }
          dbg(ans);
        } else {
          cout << "? " << "0" + ans << endl;
          cin >> ok;
          if (ok) ans = "0" + ans;
          else ans = "1" + ans;
          dbg(ans);
        }
      }
      cout << "! " << ans << endl;
    }

    return 0;
}
