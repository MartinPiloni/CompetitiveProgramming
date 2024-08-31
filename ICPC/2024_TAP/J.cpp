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

    int n, x;
    cin >> n >> x;

    vector<int> l, u, m;
    int a;
    if (x & 1) {
      for (int i = 0; i < n; i++) {
        cin >> a;
        if (a <= x / 2) l.pb(a);
        else u.pb(a);
      }
    } else {
        for (int i = 0; i < n; i++) {
          cin >> a;
          if (a < x / 2) l.pb(a);
          else if (a == x / 2) m.pb(a);
          else u.pb(a);
        }
    }

    if ((n & 1 && sz(m) > (n / 2) + 1) || (n % 2 == 0 && sz(m) > n / 2)) {
        cout << "*\n";
        return 0;
    }

    sort(all(u));
    sort(all(l));
    if (sz(m) == 0 && sz(u) && sz(l)) {
      if (l[sz(l) - 1] + u[0] == x) {
        reverse(all(u));
        if (l[sz(l) - 1] + u[0] == x) {
          reverse(all(l));
        }
      }

      if (l[sz(l) - 1] + u[0] == x) {
        cout << "*\n";
      } else {
        for (auto e : l) cout << e << " ";
        for (auto e : u) cout << e << " ";
        cout << "\n";
      }
    } else if (sz(m) == 0 && sz(l)) {
      for (auto e : l) cout << e << " ";
      cout << "\n";
    } else if (sz(m) == 0 && sz(u)){
      for (auto e : u) cout << e << " ";
      cout << "\n";
    } else if (sz(m) > 0 && sz(l) > 0 && sz(u) == 0) {
      ll cnt = 0;
      for (int i = 0; i < sz(l); i++) {
        if (cnt < sz(m)) {
          cout << m[0] << " ";
          cnt++;
        }
        cout << l[i] << " ";
      }
      if (cnt < sz(m)) cout << m[0];
      cout << "\n";
    } else if (sz(m) > 0 && sz(u) > 0 && sz(l) == 0) {
        ll cnt = 0;
        for (int i = 0; i < sz(u); i++) {
          if (cnt < sz(m)) {
            cout << m[0] << " ";
            cnt++;
          }
          cout << u[i] << " ";
        }
        if (cnt < sz(m)) cout << m[0];
        cout << "\n";
    } else {
        ll cnt = 0;
        for (int i = 0; i < sz(l); i++) {
          if (cnt < sz(m) - 1) {
            cout << m[0] << " ";
            cnt++;
          }
          cout << l[i] << " ";
        }
        cout << m[0] << " ";
        cnt++;
        for (int i = 0; i < sz(u); i++) {
          cout << u[i] << " ";
          if (cnt < sz(m)) {
            cout << m[0] << " ";
            cnt++;
          }
        }

        if (cnt < sz(m)) cout << m[0];
        cout << "\n";
      }

    return 0;
}
