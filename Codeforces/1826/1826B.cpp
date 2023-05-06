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
        int n;
        cin >> n;
        
        vector<ll> v(n);
        for (int i = 0; i < n; i++) {
            cin >> v[i];
        }
        
        if (n == 1) {
            cout << "0\n";
            continue;
        }

        ll ans = 0;
        for (int i = 0; i < n / 2; i++) {
            ans = gcd(ans, abs(v[n - 1 - i] - v[i]));
            if (ans == 1) break;
        }

        cout << ans << "\n";
    }

    return 0;
}
