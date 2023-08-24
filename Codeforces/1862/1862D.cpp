#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define fst first
#define snd second
#define sz(x) ((int)x.size())
#define all(x) x.begin(),x.end()

using ll = long long;
using str = string;

bool can(ll x, ll n) {
    if (x > 3 * (ll)1e9) return false;

    if (x * (x - 1) / 2 <= n) return true;
    else return false;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        ll n;
        cin >> n;

        ll l = 0, r = n, m;
        while (l <= r) {
            m = (l + r) / 2;
            if (can(m, n)) l = m + 1;
            else r = m - 1;
        }

        r += n - r * (r - 1LL) / 2;
        cout << r << "\n";
    }

    return 0;
}
