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
      int x, y, z;
      cin >> x >> y >> z;

      if (x + z == 2 * y) cout << "0\n";
      else cout << "1\n";
    }

    return 0;
}
