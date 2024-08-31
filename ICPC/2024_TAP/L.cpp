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

    int n, q;
    cin >> n >> q;
    vector<ll> v(n), ps_e(n + 1), ps_2(n + 1), ps_1(n + 1);
    for (int i = 0; i < n; i++) {
      cin >> v[i];
      ps_e[i + 1] = ps_e[i] + (v[i] & 1 ? v[i] : 0);
      ps_1[i + 1] = ps_2[i] + (v[i] == 1 ? 1 : 0);
      ps_2[i + 1] = ps_2[i] + (__builtin_popcount((v[i])) == 1 ? v[i] : 0);
    }

    while(q--) {
      int l, r;
      cin >> l >> r;
      l--; r--;

      ll a = ps_2[r + 1] - ps_2[l];
      ll b = ps_e[r + 1] - ps_e[l];
      ll ones = ps_1[r + 1] - ps_1[l];

      a -= ones / 2;
      if (ones & 1) ones++;
      b -= ones / 2;

      if (a > b) cout << "A\n";
      else if (b > a) cout << "B\n";
      else cout << "E\n";
    }
    

    return 0;
}
