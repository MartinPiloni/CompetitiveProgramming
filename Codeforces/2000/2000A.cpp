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
      str s;
      cin >> s;

      if (sz(s) <= 2) {
        cout << "NO\n";
        continue;
      }

      bool ok = true;
      ok &= (s[0] == '1' && s[1] == '0');
      ok &= (s[2] >= '2' || (sz(s) > 3 && s[2] == '1'));

      (ok ? cout << "YES\n" : cout << "NO\n");
    }

    return 0;
}
