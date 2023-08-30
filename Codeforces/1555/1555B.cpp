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
        ll w, h;
        cin >> w >> h;

        ll x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;

        ll w2, h2;
        cin >> w2 >> h2;

        ll ans = 1e9;
        if (y2 + h2 - y1 <= h) {
            ans = min(ans, max(h2 - y1, 0LL));
            ans = min(ans, max(y2 - (h - h2), 0LL));
        }
        if (x2 + w2 - x1 <= w) {
            ans = min(ans, max(w2 - x1, 0LL));
            ans = min(ans, max(x2 - (w - w2), 0LL));
        }

        if (ans == (ll)1e9) ans = -1;
        cout << ans << "\n";
    }

    return 0;
}
