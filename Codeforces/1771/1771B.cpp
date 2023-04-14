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
        ll n, m;
        cin >> n >> m;
        
        vector<ll> v(n, n);
        ll a, b;
        for (int i = 0; i < m; i++) {
            cin >> a >> b;
            a--; b--;
            (a < b ? v[a] = min(v[a], b) : v[b] = min(v[b], a));
        }

        for (ll i = n - 1; i > 0; i--) {
            v[i - 1] = min(v[i], v[i - 1]);
        }

        ll ans = 0;
        for (int i = 0; i < n; i++) {
            ans += v[i] - i;
        }

        cout << ans << "\n";
    }

    return 0;
}
