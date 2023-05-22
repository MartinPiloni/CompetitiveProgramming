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

        vector<pair<ll, ll>> a(n);
        vector<ll> b(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i].first;
            a[i].second = i;
        }
        for (int i = 0; i < n; i++) {
            cin >> b[i];
        }
        sort(a.begin(), a.end());
        sort(b.begin(), b.end());

        vector<ll> ans(n);
        for (int i = 0; i < n; i++) {
            ans[a[i].second] = b[i];
        }

        for (int i = 0; i < n; i++) {
            cout << ans[i] << " \n"[i == n - 1];
        }
    }

    return 0;
}
