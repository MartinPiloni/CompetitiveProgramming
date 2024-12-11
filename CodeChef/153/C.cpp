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
      vector<int> v(3);
      for (int i = 0; i < 3; i++) cin >> v[i];
      sort(all(v));
      if (v[2] <= v[0] + v[1]) cout << "YES\n";
      else cout << "NO\n";
    }

    return 0;
}

