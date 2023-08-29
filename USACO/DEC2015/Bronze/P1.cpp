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
    setIO("paint");

    int a, b, c, d;
    cin >> a >> b >> c >> d;

    ll ans = b - a + d - c;
    if (a <= c && d <= b) ans -= d - c;
    else if (c <= a && b <= d) ans -= b - a;
    else if (a <= c && c < b) ans -= b - c;
    else if (c <= a && a < d) ans -= d - a;
    cout << ans << "\n";
    

    return 0;
}
