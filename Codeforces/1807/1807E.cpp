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
        vector<ll> s(n + 1);
        for (int i = 1; i <= n; i++) {
            cin >> s[i];
            s[i] += s[i - 1];
        }
        int l = 1, r = n, m;
        while (l != r) {
            m = (l + r) / 2;
            cout << "? " << m - l + 1;
            for (int i = l; i <= m; i++) {
                cout << " " << i ;
            }
            cout << endl;
            ll q; cin >> q;
            if (q > s[m] - s[l - 1]) r = m;
            else l = m + 1;
        }
        cout << "! " << l << endl;
    }

    return 0;
}
