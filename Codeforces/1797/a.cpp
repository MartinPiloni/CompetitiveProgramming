#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using str = string;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;

        int x1, x2, y1, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        int ans = 0;

        if ((x1 == 1 && y1 == 1) || (x1 == n && y1 == m) || (x1 == 1 && y1 == m) || (x1 == n && y1 == 1) ||
            (x2 == 1 && y2 == 1) || (x2 == n && y2 == m) || (x2 == 1 && y2 == m) || (x2 == n && y2 == 1)) {
            ans = 2;
        } else if (x1 == 1 || y1 == 1 || x1 == n || y1 == m || x2 == 1 || y2 == 1 || x2 == n || y2 == m) {
            ans = 3;
        } else {
            ans = 4;
        }

        cout << ans << "\n";
    }
    return 0;
}
