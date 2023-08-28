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

    ll n, k, m = 0;
    cin >> n >> k;
    vector<ll> v(n);
    for (int i = 0; i < n; i++) {cin >> v[i]; m = max(m, v[i]);};

    ll cnt = 0;
    ll ans = v[0];
    for (int i = 1; i < n; i++) {
        if (ans > v[i]) cnt++;
        else {
            ans = v[i];
            cnt = 1;
        }

        if (cnt == k || ans == m) break;
    }

    cout << ans << "\n";
    return 0;
}
