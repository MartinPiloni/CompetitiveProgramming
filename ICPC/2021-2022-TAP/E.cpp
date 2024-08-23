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
    deque<ll> l, r;

    ll x, d, turn = 0;
    for (int i = 0; i < n; i++) {
      cin >> x >> d;
      if (i == 0) turn = d;

      if (d == 0) l.push_back(x);
      else r.push_back(x);
    }

    ll t = 0;
    while (!l.empty() || !r.empty()) {
      if (turn == 0) {
        if (!l.empty() && l.front() < t) {
          while (!l.empty() && l.front() < t) l.pop_front();
          l.push_front(t);
        }

        while (!l.empty()) {
          t = l.front() + 10;
          l.pop_front();

          if (!l.empty() && t < l.front()) break;
        }

        if (l.empty() || (!r.empty() && r.front() < l.front())) turn ^= 1;
      } else {
        if (!r.empty() && r.front() < t) {
          while (!r.empty() && r.front() < t) r.pop_front();
          r.push_front(t);
        }

        while (!r.empty()) {
          t = r.front() + 10;
          r.pop_front();

          if (!r.empty() && t < r.front()) break;
        }

        if (r.empty() || (!l.empty() && l.front() < r.front())) turn ^= 1;
      }
    }
    cout << t << "\n";

    return 0;
}
