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
        ll n;
        cin >> n;

        ll ans = 0;
        ans += 4 * n + n - 1 + 4 + 3;
        ans += 2 * (((n - 2) * (n - 1) / 2) - (2 * 3 / 2));

        cout << ans << "\n";
    }

    return 0;
}
