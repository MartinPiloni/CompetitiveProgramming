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
        ll k, x;
        cin >> k >> x;
        
        ll l = 1, r = 2 * k - 1, m, sum, ans = 2 * k - 1;
        while (l <= r) {
            m = (l + r) / 2;
            sum = 0;

            if (m <= k) sum = m * (m + 1) / 2;
            else {
                sum = k * (k + 1) / 2;
                sum += ((k - 1) * k / 2) - ((2 * k - 1 - m) * (2 * k - 1 - m + 1) / 2);
            }

            if (sum >= x) {
                ans = m;
                r = m - 1;
            }
            else l = m + 1;
        }
        cout << ans << "\n";
    }

    return 0;
}
