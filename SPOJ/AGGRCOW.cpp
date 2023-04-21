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
        ll n, c;
        cin >> n >> c;

        vector<ll> stall(n);
        for (int i = 0; i < n; i++) {
            cin >> stall[i];
        }
        sort(stall.begin(), stall.end());

        ll j = 0, s = 1;
        ll l = 1, r = (stall[n - 1] - stall[0]), m;
        while(l <= r) {
            s = 1; j = 0;
            m = (l + r) / 2;
            for (int i = 1; i < n; i++) {
                if (stall[i] - stall[j] >= m) {
                    j = i;
                    s++;
                }
            }

            if (s >= c) l = m + 1;
            else r = m - 1;
        }

        cout << r << "\n";
    }

    return 0;
}
