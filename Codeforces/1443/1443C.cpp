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

        vector<ll> d(n), p(n);
        for (int i = 0; i < n; i++) {
            cin >> d[i];
        }

        for (int i = 0; i < n; i++) {
            cin >> p[i];
        }

        ll l = 1, r = 1e9, m, sum;
        while (l <= r) {
            sum = 0;
            m = (l + r) / 2;
            for (int i = 0; i < n; i++) {
                if (d[i] > m) sum += p[i];
            }

            if (sum <= m) r = m - 1;
            else l = m + 1;
        }  

        cout << l << "\n";
    }
    return 0;
}
