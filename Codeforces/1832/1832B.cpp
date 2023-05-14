#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using str = string;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while(t--) {
        int n, k;
        cin >> n >> k;

        vector<ll> v(n);
        for (int i = 0; i < n; i++) {
            cin >> v[i];
        }
        sort(v.begin(), v.end());

        vector<ll> ps(n + 1, 0);
        for (int i = 1; i < n + 1; i++) {
            ps[i] += ps[i - 1] + v[i - 1];
        }

        ll ans = 0;
        for (int i = 0; i <= k; i++) {
            ans = max(ans, ps[n - i] - ps[2 * (k - i)]);
        }

        cout << ans << "\n";
    }
    return 0;
}
