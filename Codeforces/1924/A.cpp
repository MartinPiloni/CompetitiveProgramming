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
      int n, k, m;
      str s;
      cin >> n >> k >> m >> s;;

      int cnt = 0;
      set<char> seen;
      bool can = false;
      str cant = "";
      for (int i = 0; i < m; i++) {
        seen.insert(s[i]);
        
        if (sz(seen) == k) {
          cnt++;
          cant += s[i];
          seen.clear();
        }

        if (cnt == n) {
          can = true;
          break;
        }
      }

      if (can) cout << "YES\n";
      else {
        cout << "NO\n";
        vector<bool> v(k);
        for (auto e : seen) v[e - 'a'] = 1;
        for (int i = 0; i < k; i++) {
          if (v[i] == 0) {
            while (sz(cant) < n) cant += char('a' + i);
            break;
          }
        }
        cout << cant << "\n";
      }
    }

    return 0;
}
