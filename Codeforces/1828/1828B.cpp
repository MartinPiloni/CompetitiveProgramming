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
        
        vector<int> v(n);
        for (int i = 0; i < n; i++) {
            cin >> v[i];
        }

        int ans = 0;
        for (int i = 0; i < n; i++) {
            ans = gcd(ans, abs(v[i] - (i + 1)));
        }

        cout << ans << "\n";
    }

    return 0;
}
