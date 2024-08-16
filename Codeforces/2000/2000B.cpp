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

      vector<int> v(n);
      for (int i = 0; i < n; i++) {
        cin >> v[i];
      }

      vector<bool> seats(2e5 + 10);
      seats[v[0]] = true;
      bool ok = true;
      for (int i = 1; i < n; i++) {
        if (!seats[v[i] - 1] && !seats[v[i] + 1]) {
          ok = false;
          break;
        } else {
          seats[v[i]] = true;
        }
      }

      (ok ? cout << "YES\n" : cout << "NO\n");
    }

    return 0;
}
