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
      int n;
      cin >> n;

      vector<pair<int, int>> v;
      for (int i = 1; i < n; i++) {
        ll prev = 0;
        ll x = 1;
        while (x != prev) {
          cout << "? " << x << " " << i + 1 << endl;
          prev = x;
          cin >> x;
        }
        v.pb({prev, i + 1});
      }
      cout << "! ";
      for (auto e : v) {
        cout << e.fst << " " << e.snd << " ";
      }
      cout << endl;
    }

    return 0;
}
