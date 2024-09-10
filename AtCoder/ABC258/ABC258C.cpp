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

    int n, q;
    str s;
    cin >> n >> q >> s;

    ll shifts = 0;
    while (q--) {
      int ty, x;
      cin >> ty >> x;
      if (ty == 1) {
        shifts = (shifts + x) % n;
      } else {
        x--;
        cout << s[(x + n - shifts) % n] << "\n";
      }
    }


    return 0;
}
