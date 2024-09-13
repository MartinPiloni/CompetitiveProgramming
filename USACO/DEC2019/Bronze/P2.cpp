#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using str = string;

#define sz(x) int((x).size())

void setIO(string name = "") {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    if ((int) name.size()) {
        freopen((name + ".in").c_str(), "r", stdin);
        freopen((name + ".out").c_str(), "w", stdout);
    }
}

int main() {
    setIO("whereami");

    int n;
    str s;
    cin >> n >> s;
    for (int i = 1; i < n; i++) {
      bool can = true;
      map<str, ll> freq;
      for (int j = 0; j < n - i + 1; j++) {
        auto sub = s.substr(j, i);
        freq[sub]++;

        if (freq[sub] > 1) {
          can = false;
          break;
        }
      }

      if (can) {
        cout << i << "\n";
        break;
      }
    }

    return 0;
}
