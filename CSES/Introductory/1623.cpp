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

    int n;
    cin >> n;
    vector<ll> v(n);
    for (int i = 0; i < n; i++) cin >> v[i];

    ll ans = 1e18;
    for (int mask = 0; mask < 1 << n; mask++) {
      ll g1 = 0, g2 = 0;
      for (int i = 0; i < n; i++) {
        if (mask & 1 << i) g1 += v[i];
        else g2 += v[i];
      }
      ans = min(ans, abs(g2 - g1));
    }
    cout << ans << "\n";

    return 0;
}
