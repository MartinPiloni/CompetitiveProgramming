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
        ll n, k;
        cin >> n >> k;

        vector<vector<ll>> v(k);
        ll c;
        for (ll i = 0; i < n; i++) {
            cin >> c;
            c--;
            v[c].pb(i);
        }

        ll ans = 1e18;
        for (int i = 0; i < k; i++) {
            if (sz(v[i]) > 0) {
                ll mx = v[i][0] - 0;
                ll prev_mx = 0;
                for (int j = 0; j < sz(v[i]) - 1; j++) {
                    if (v[i][j + 1] - v[i][j] - 1 <= mx &&  v[i][j + 1] - v[i][j] - 1 > prev_mx) {
                        prev_mx = v[i][j + 1] - v[i][j] - 1;
                    } else if (v[i][j + 1] - v[i][j] - 1 > mx) prev_mx = mx;
                    mx = max(mx, v[i][j + 1] - v[i][j] - 1);
                }

                if (n - v[i][sz(v[i]) - 1] - 1 <= mx && n - v[i][sz(v[i]) - 1] - 1 > prev_mx) {
                    prev_mx = n - v[i][sz(v[i]) - 1] - 1;
                } else if (n - v[i][sz(v[i]) - 1] - 1 > mx) prev_mx = mx;
                mx = max(mx, n - v[i][sz(v[i]) - 1] - 1);

                mx = max(mx / 2, prev_mx);
                ans = min(ans, mx);
            }
        } 

        cout << ans << '\n';
    }

    return 0;
}
