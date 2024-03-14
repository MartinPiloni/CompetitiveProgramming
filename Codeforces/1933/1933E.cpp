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
        int n;
        cin >> n;
        vector<int> ps(n + 1);
        
        int x;
        for (int i = 0; i < n; i++) {
            cin >> x;
            ps[i + 1] = ps[i] + x;
        }

        int q;
        cin >> q;
        while (q--) {
            ll l, u;
            cin >> l >> u;

            u += ps[l - 1];
            ll ans = upper_bound(all(ps), u) - ps.begin();
            u -= ps[l - 1];

            if (ans == ps.end() - ps.begin()) cout << n << " ";
            else {
                ll tracks = ps[ans] - ps[l - 1];
                ll tracks2 = ps[ans - 1] - ps[l - 1];

                if (ans - 1 < l || (tracks * u - tracks * (tracks - 1) / 2 > tracks2 * u - tracks2 * (tracks2 - 1) / 2)) {
                    cout << ans << " ";
                } else {
                    cout << ans - 1 << " ";
                }
            }
        }
        cout << "\n";
    }

    return 0;
}
