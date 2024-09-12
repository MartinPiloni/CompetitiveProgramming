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
    n *= 2;
    vector<ll> v(n);
    for (int i = 0; i < n; i++) cin >> v[i];
    sort(all(v));

    ll ans = 1e9;
    for (int i = 0; i < n; i++) {
      for (int j = i + 1; j < n; j++) {
        ll sum = 0, diff = 0;
        for (int k = 0; k < n; k++) {
          if (k == i || k == j) continue;
          
          if (diff == 0) {
            diff -= v[k];
          } else if (diff < 0) {
            diff += v[k];
            sum += diff;
            diff = 0;
          }
        }
        ans = min(ans, sum);
      }
    }
    cout << ans << "\n";
    
    return 0;
}
