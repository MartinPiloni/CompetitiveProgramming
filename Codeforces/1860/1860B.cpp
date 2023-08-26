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
        ll m, k, oc, kc;
        cin >> m >> k >> oc >> kc;
        if (k * kc <= m) m -= k * kc;
        else m -= k * (m / k);

        if (oc > m) m = 0;
        else if (oc > m % k) {
            oc -= m % k;
            m -= m % k;
            m -= k * (oc / k);
        } else {
            m -= oc;
        }

        ll ans = 0;
        if (m > 0) {
            ans = m / k;
            m -= ans * k;
            ans += m;
        }
        cout << ans << "\n";
    }

    return 0;
}
