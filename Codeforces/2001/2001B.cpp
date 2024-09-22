#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define fst first
#define snd second
#define int long long
#define sz(x) ((int)x.size())
#define all(x) x.begin(),x.end()
#define dbg(x) cerr << #x << ": " << (x) << endl

using ll = long long;
using str = string;

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
      int n;
      cin >> n;

      if (n & 1) {
        deque<ll> q;
        for (int i = 0; i < n; i++) q.push_back(i + 1);
        for (int i = 0; i < n; i++) {
          if (!(i & 1)) {
            cout << q.front() << " ";
            q.pop_front();
          } else {
            cout << q.back() << " ";
            q.pop_back();
          }
        }
        cout << "\n";
      } else {
        cout << "-1\n";
      }
    }

    return 0;
}
