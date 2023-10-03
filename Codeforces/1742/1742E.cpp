#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define fst first
#define snd second
#define sz(x) ((int)x.size())
#define all(x) x.begin(),x.end()

using ll = long long;
using str = string;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        int n, q;
        cin >> n >> q;
        vector<ll> v(n), sum(n + 1), m(n + 1);
        for (int i = 0; i < n; i++) {
            cin >> v[i];
            m[i + 1] = max(m[i], v[i]);
            sum[i + 1] = sum[i] + v[i];
        }

        ll x;
        while (q--) {
            cin >> x;
            cout << sum[upper_bound(all(m), x) - m.begin() - 1] << " \n"[q == 0];
        }
    }

    return 0;
}
