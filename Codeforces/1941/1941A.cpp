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
        int n, m, k;
        cin >> n >> m >> k;
        
        vector<ll> l(n), r(m);
        for (int i = 0; i < n; i++) cin >> l[i];
        for (int i = 0; i < m; i++) cin >> r[i];
        sort(all(l));
        sort(all(r));

        ll ans = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (l[i] + r[j] <= k) ans++;
                else break;
            }
        }
        cout << ans << "\n";
    }

    return 0;
}
