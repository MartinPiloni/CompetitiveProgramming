#include <algorithm>
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
    cin >> n >> q;

    map<ll, ll> freq;
    vector<pair<ll, pair<ll, ll>>> v(n);
    for (int i = 0; i < n; i++) {
      cin >> v[i].fst;
      freq[v[i].fst]++;
      v[i].snd.fst = freq[v[i].fst];
      v[i].snd.snd = i;
    }
    sort(all(v));

    ll x, k;
    while (q--) {
      cin >> x >> k;
      auto it = lower_bound(all(v), make_pair(x, make_pair(k, 0LL)));
      if (it->fst == x) cout << it->snd.snd + 1 << "\n";
      else cout << "-1\n";
    }


    return 0;
}
