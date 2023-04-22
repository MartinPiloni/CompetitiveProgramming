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
        ll n, l, r;
        cin >> n >> l >> r;

        vector<ll> a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        sort(a.begin(), a.end());

        ll ans = 0, l_i, r_i;
        for (int i = 0; i < n; i++) {
            l_i = r_i = 0;
            if (a[i] < l) l_i = lower_bound(a.begin() + i + 1, a.end(), l - a[i]) - (a.begin() + i + 1); 
            if (a[i] < r) r_i = upper_bound(a.begin() + i + 1, a.end(), r - a[i]) - (a.begin() + i + 1);
            ans += r_i - l_i;
        }

        cout << ans << "\n";
    }

    return 0;
}
