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

        ll in;
        vector<ll> a(n, 0);
        for (int i = 0; i < m; i++) {
            cin >> in;
            a[in - 1]++;
        }

        ll l = 1, r = 2 * m, mid, tasks;
        while (l <= r) {
            tasks = 0;
            mid = (l + r) / 2;
            for (int i = 0; i < n; i++) {
                tasks += min(mid, a[i]) + (mid - min(mid, a[i])) / 2;
            }
            
            if (tasks >= m) r = mid - 1;
            else l = mid + 1;
        }
        cout << l << "\n";
    }

    return 0;
}
