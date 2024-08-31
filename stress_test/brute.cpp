#include <algorithm>
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
    vector<int> v(n);
    for (int i = 0; i < n; i++) cin >> v[i];
    sort(all(v));

    bool ok = true;
    do {
      ok = true;
      for (int i = 1; i < n; i++) {
        if (v[i] + v[i - 1] == x) {
          ok = false; 
          break;
        }
      }

      if (ok) break;
    } while (next_permutation(all(v)));

    if (!ok) cout << "*\n";
    else {
      for (auto e : v) cout << e << " ";
      cout << "\n";
    }

    return 0;
}
