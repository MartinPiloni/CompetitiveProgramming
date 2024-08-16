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
      for (int i = 0; i < n; i++) cin >> v[i];
      
      int m;
      cin >> m;
      vector<str> s(m); 
      for (int i = 0; i < m; i++) cin >> s[i];

      for (int i = 0; i < m; i++) {
        bool ok = true;
        if (sz(v) != sz(s[i])) {
          cout << "NO\n";
          continue;
        }

        map<int, char> corr_i_c;
        map<char, int> corr_c_i;
        for (int j = 0; j < sz(s[i]); j++) {
          if (corr_i_c.count(v[j]) == 0) {
            corr_i_c[v[j]] = s[i][j];
          } else if (corr_i_c[v[j]] != s[i][j]) {
            ok = false;
            break;
          }

          if (corr_c_i.count(s[i][j]) == 0) {
            corr_c_i[s[i][j]] = v[j];
          } else if (corr_c_i[s[i][j]] != v[j]) {
            ok = false;
            break;
          }
        }
        (ok ? cout << "YES\n" : cout << "NO\n");
      }
    }

    return 0;
}
