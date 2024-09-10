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

    str s;
    cin >> s;

    if (sz(s) == 1) {
      cout << "0\n";
      return 0;
    }

    str sub = s.substr(0, sz(s) / 2);
    if (sz(s) & 1) for (int i = 0; i < sz(sub); i++) sub[i] = '9';

    ll ans = 0;
    for (int i = 1; i <= stoll(sub); i++) {
      str cand = to_string(i) + to_string(i);
      if (stoll(cand) <= stoll(s)) ans++;
    }
    cout << ans << "\n";

    return 0;
}
