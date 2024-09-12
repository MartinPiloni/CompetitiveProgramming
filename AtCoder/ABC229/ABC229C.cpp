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

    int n, w;
    cin >> n >> w;
    vector<pair<ll, ll>> v(n);
    for (int i = 0; i < n; i++) {
      cin >> v[i].fst;
      cin >> v[i].snd;
    }
    sort(all(v));
    reverse(all(v));

    ll ans = 0, grams = 0;
    for (int i = 0; i < n; i++) {
      if (grams + v[i].snd <= w) {
        ans += v[i].fst * v[i].snd;
        grams += v[i].snd;
      } else {
        ans += v[i].fst * (w - grams); 
        grams = w;
      }

      if (grams == w) break;
    }
    cout << ans << "\n";

    return 0;
}
