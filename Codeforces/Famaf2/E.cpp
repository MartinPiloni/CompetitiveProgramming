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
        int n;
        cin >> n;

        vector<pair<int, int>> v(n);
        for (int i = 0; i < n; i++) {
            cin >> v[i].first;
            cin >> v[i].second;
        }

        int l = 1, r = n, m;
        while (l <= r) {
            m = (l + r) / 2;

            int c = 0;
            for (int i = 0; i < n; i++) {
                if (v[i].first >= m - 1 - c && v[i].second >= c) {
                    c++;
                }
            }

            if (c >= m) l = m + 1;
            else r = m - 1;
        }
        cout << r << "\n";
    }

    return 0;
}
