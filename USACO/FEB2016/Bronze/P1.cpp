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
    setIO("pails");

    int x, y, m;
    cin >> x >> y >> m;

    ll s = 0, ans = 0;
    for (int i = 0; i <= m / x; i++) {
        s = i * x;
        while (s + y <= m) {
            s += y; 
        }
        ans = max(ans, s);
    }
    cout << ans << "\n";

    return 0;
}
