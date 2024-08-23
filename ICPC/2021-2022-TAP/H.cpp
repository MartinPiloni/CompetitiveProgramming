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

    int n, k;
    cin >> n >> k;
    vector<priority_queue<ll>> c(k);
    vector<ll> order;

    ll x, co;
    for (int i = 0; i < n; i++) {
      cin >> x >> co;
      co--;
      c[co].push(-x);
      order.pb(co);
    }

    ll mini = 0;
    bool can = true;
    for (int i = 0; i < n; i++) {
      co = order[i];
      if (c[co].top() * -1 < mini) {
        can = false;
        break;
      } else {
        mini = c[co].top() * -1;
        c[co].pop();
      }
    }
    (can ? cout << "Y\n" : cout << "N\n");

    return 0;
}
