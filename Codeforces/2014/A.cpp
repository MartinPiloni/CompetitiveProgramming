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
      int n, k;
      cin >> n >> k;
      vector<int> v(n);
      for (int i = 0; i < n; i++) cin >> v[i];

      ll cnt = 0, ans = 0;
      for (int i = 0; i < n; i++) {
        if (v[i] >= k) cnt += v[i];
        else if (v[i] == 0 && cnt > 0) {
          cnt--;
          ans++;
        }
      }
      cout << ans << "\n";
      
    }

    return 0;
}
