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

      ll x = n - k + 1;
      ll odd;
      if (x & 1) {
        odd = (n - x + 2) / 2;
      } else {
        odd = (n - x + 1) / 2;
      }
      (odd % 2 == 0 ? cout << "YES\n" : cout << "NO\n");
    }

    return 0;
}
