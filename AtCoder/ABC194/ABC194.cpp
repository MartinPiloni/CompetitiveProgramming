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

    map<ll, ll> freq;
    int n;
    cin >> n;

    ll x;
    ll ans = 0;
    for (int i = 0; i < n; i++) {
      cin >> x;
      freq[x]++;

      for (auto e : freq) {
        if (e.fst != x) ans += (abs(x - e.fst) * abs(x - e.fst)) * e.snd;
      }
    }
    cout << ans << "\n";

    return 0;
}
