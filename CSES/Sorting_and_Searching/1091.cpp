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

    int n, m;
    cin >> n >> m;

    multiset<ll> s;
    ll x;
    for (int i = 0; i < n; i++) {
      cin >> x;
      s.insert(x);
    }

    for (int i = 0; i < m; i++) {
      cin >> x;
      auto it = s.upper_bound(x);
      if (it == s.begin()) {
        cout << "-1\n";
        continue;
      } else {
        it--;
      }
      cout << *it << "\n";
      s.erase(s.find(*it));
    }

    return 0;
}
