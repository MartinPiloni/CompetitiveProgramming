#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using str = string;

#define sz(x) int((x).size())
#define fst first
#define snd second 
#define pb push_back

void setIO(string name = "") {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    if ((int) name.size()) {
        freopen((name + ".in").c_str(), "r", stdin);
        freopen((name + ".out").c_str(), "w", stdout);
    }
}

int main() {
    setIO("notlast");

    int n;
    cin >> n;
    map<str, ll> m = {{"Bessie", 0}, {"Elsie", 0}, {"Daisy", 0}, {"Gertie", 0}, {"Annabelle", 0}, {"Maggie", 0}, {"Henrietta", 0}};

    str s;
    ll x;
    for (int i = 0; i < n; i++) {
      cin >> s >> x;
      m[s] += x;
    }

    vector<pair<ll, str>> v;
    for (auto e : m) {
      v.pb({e.snd, e.fst});
    }
    sort(v.begin(), v.end());

    str ans = "Tie";
    for (int i = 1; i < sz(v); i++) {
      if (v[i].fst == v[0].fst) continue;

      if (i == sz(v) - 1 || v[i + 1].fst > v[i].fst) {
        ans = v[i].snd;
        break;
      }
      else if (v[i + 1].fst == v[i].fst) {
        break;
      }
    }
    cout << ans << "\n";

    return 0;
}
