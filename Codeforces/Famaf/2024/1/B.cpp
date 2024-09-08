#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define fst first
#define snd second
#define sz(x) ((int)x.size())
#define all(x) x.begin(),x.end()
#define dbg(x) cerr << #x << ": " << (x) << endl

using ll = long long;
using str = string;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
      vector<pair<ll, ll>> v(3);
      for (int i = 0; i < 3; i++) {
        cin >> v[i].fst;
        v[i].snd = i;
      }
      sort(all(v));
      reverse(all(v));

      if (v[0].fst == v[2].fst) {
        cout << "1 1 1\n";
        continue;
      }

      vector<ll> ans(3);
      if (v[0].fst == v[1].fst) {
        ans[v[0].snd] = 1;
        ans[v[1].snd] = 1;
      } else {
        ans[v[0].snd] = 0;
        ans[v[1].snd] = v[0].fst - v[1].fst + 1;
      }
      ans[v[2].snd] = v[0].fst - v[2].fst + 1;
      for (int i = 0; i < 3; i++) cout << ans[i] << " \n"[i == 2];
    }

    return 0;
}
