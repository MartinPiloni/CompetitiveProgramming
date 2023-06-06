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
    setIO("lostcow");

    int x, y;
    cin >> x >> y;

    int ans = 0, pos = x, last_pos = x, p = 1;
    if (x > y) {
        while (pos > y) {
            pos = x + p;
            p *= -2;
            ans += abs(last_pos - x) + abs(pos - x);
            last_pos = pos;
        }
    }
    else if (x < y) {
        while (pos < y) {
            pos = x + p;
            p *= -2;
            ans += abs(last_pos - x) + abs(pos - x);
            last_pos = pos;
        }
    }

    ans -= abs(y - pos);
    cout << ans << "\n";
    return 0;
}
