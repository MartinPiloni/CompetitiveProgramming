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

        int max = 0, min = 1e9;
        vector<int> a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
            if (a[i] > max) max = a[i];
            if (a[i] < min) min = a[i];
        }

        if (max == min) {
            cout << n * (n-1) << "\n";
        } else {
            ll max_e = 0, min_e = 0;
            for (int i = 0; i < n; i++) {
                if (a[i] == max) max_e++;
                else if (a[i] == min) min_e++;
            }
            cout << 2 * max_e * min_e << "\n";
        }
    }

    return 0;
}
