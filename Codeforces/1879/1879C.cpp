#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define fst first
#define snd second
#define sz(x) ((int)x.size())
#define all(x) x.begin(),x.end()

using ll = long long;
using str = string;

const ll MOD = 998244353;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    vector<ll> f(2e5 + 10);
    f[0] = 1;
    for (int i = 1; i < 2e5 + 10; i++) {
        f[i] = (f[i - 1] % MOD * i % MOD) % MOD;
    }

    int t;
    cin >> t;
    while (t--) {
        str s;
        cin >> s;

        ll cnt = 1, ans = 0, groups = 1;
        for (int i = 1; i < sz(s); i++) {
            if (s[i] == s[i - 1]) cnt++;
            else if (cnt > 1) {
                ans += cnt - 1;
                groups = (groups % MOD * cnt % MOD) % MOD;
                cnt = 1;
            } else {
                cnt = 1;
            }
        }

        if (cnt > 1) {
            ans += cnt - 1;
            groups = (groups % MOD * cnt % MOD) % MOD;
        }
        cout << ans << " " << (f[ans] % MOD * groups % MOD) % MOD << "\n";
    }

    return 0;
}
