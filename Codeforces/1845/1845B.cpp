#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using str = string;

#define sz(x) int((x).size())

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while(t--) {
        int x, y;
        cin >> x >> y;

        int x_b, y_b, x_c, y_c;
        cin >> x_b >> y_b >> x_c >> y_c;

        int ans = 1;
        if (x < x_b && x < x_c) {
            ans += (min(x_b - x, x_c - x));
        } else if (x_b < x && x_c < x) {
            ans += min(x - x_b, x - x_c);
        }

        if (y < y_b && y < y_c) {
            ans += min(y_b - y, y_c - y);
        } else if (y > y_b && y > y_c) {
            ans += min(y - y_b, y - y_c);
        }

        cout << ans << "\n";
    }

    return 0;
}
