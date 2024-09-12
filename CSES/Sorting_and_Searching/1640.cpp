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

    int n, x;
    cin >> n >> x;

    vector<ll> v(n);
    map<ll, ll> freq;
    for (int i = 0; i < n; i++) {
      cin >> v[i];
      freq[v[i]]++;
    }

    bool can = false;
    for (int i = 0; i < n; i++) {
      if ((x - v[i] == v[i] && freq[x - v[i]] > 1) || (x - v[i] != v[i] && freq[x - v[i]] > 0)) {
        can = true;
        cout << i + 1 << " ";
        bool seen = !(x - v[i] == v[i]);
        for (int j = 0; j < n; j++) {
          if (seen && v[j] == x - v[i]) {
            cout << j + 1 << "\n";
            break;
          }
          else if (v[j] == x - v[i]) seen = true;
        }
        break;
      }
    }
    if (!can) cout << "IMPOSSIBLE\n";

    return 0;
}
