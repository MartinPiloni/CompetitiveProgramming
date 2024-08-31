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

    int n;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++) cin >> v[i];
    ll cnt = 0, ans = 0;
    for (int i = 0; i < n; i++) {
      if (v[i] == 1) {
        ans++;
        cnt++;

        if (cnt >= 3) ans++;
      } else {
        ans--;
        cnt = 0;
      }
    }
    cout << ans << "\n";

    return 0;
}
