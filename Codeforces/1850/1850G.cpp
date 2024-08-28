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
      vector<pair<ll, ll>> p(n);
      for (int i = 0; i < n; i++) {
        cin >> p[i].fst;
        cin >> p[i].snd;
      }
      
      vector<map<ll, ll>> v(4);
      for (int i = 0; i < 4; i++) {
        v.clear();
        if (i == 0) {
          for (int j = 0; j < n; j++) {
            v[i][p[j].snd]++;
          }
        } 
        else if (i == 1) {
          for (int j = 0; j < n; j++) {
            v[i][p[j].fst]++;
          }
        }
        else if (i == 2) {
          for (int j = 0; j < n; j++) {
            v[i][p[j].fst - p[j].snd]++;
          }
        }
        else {
          for (int j = 0; j < n; j++) {
            v[i][p[j].fst + p[j].snd]++;
          }
        }
      }

      ll ans = 0;
      for (int i = 0; i < 4; i++) {
        for (auto e : v[i]) {
          ans += (e.snd * (e.snd - 1));
        }
      }
      cout << ans << "\n";
    }

    return 0;
}
