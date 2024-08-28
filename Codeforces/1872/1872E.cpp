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
      int n; cin >> n;
      vector<ll> v(n), px(n+1);
      for (int i = 0; i < n; i++) {
        cin >> v[i];
        px[i + 1] = px[i] ^ v[i];
      }
      str s; cin >> s;

      ll xor0 = 0, xor1 = 0;
      for (int i = 0; i < n; i++) {
        if (s[i] == '0') xor0 ^= v[i];
        else xor1 ^= v[i];
      }

      int q; cin >> q;
      ll ty;
      while (q--) {
        cin >> ty;
        if (ty == 1) {
          ll l, r;
          cin >> l >> r;
          l--; r--;
          xor0 ^= (px[r + 1] ^ px[l]);
          xor1 ^= (px[r + 1] ^ px[l]);
        } else {
          ll g;
          cin >> g;
          if (g == 0) cout << xor0 << " "; 
          else cout << xor1 << " ";
        }
      }
      cout << "\n";
    }

    return 0;
}
