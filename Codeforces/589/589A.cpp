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

    ll x = 1;
    vector<ll> pows2;
    while (x <= (ll)1e9) {
        pows2.pb(x);
        x <<= 1;
    }

    int t;
    cin >> t;
    while (t--) {
        cin >> x;
        ll ans = x * (x + 1) / 2;
        for (int i = 0; i < sz(pows2); i++) {
            if (pows2[i] <= x) ans -= pows2[i] * 2;
            else break;
        }
        cout << ans << "\n";
    }


    return 0;
}
