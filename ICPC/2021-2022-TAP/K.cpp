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

    int t, d, m;
    cin >> t >> d >> m;
    vector<int> v(m + 2);
    v[0] = 0;
    for (int i = 1; i < m + 1; i++) cin >> v[i];
    v[m + 1] = d;

    bool can = false;
    for (int i = 1; i < m + 2; i++) {
      if (v[i] - v[i - 1] >= t) {
        can = true;
        break;
      }
    }
    (can ? cout << "Y\n" : cout << "N\n");

    return 0;
}
