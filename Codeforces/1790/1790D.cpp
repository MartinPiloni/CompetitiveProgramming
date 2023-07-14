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
        vector<ll> v(n);
        for (int i = 0; i < n; i++) cin >> v[i];
        sort(all(v));

        vector<ll> cnt(1);
        ll curr = v[0];
        for (int i = 0; i < n; i++) {
            if (v[i] == curr) cnt[sz(cnt) - 1]++;
            else {
                if (v[i] != curr + 1) cnt.pb(0);
                curr = v[i];
                cnt.pb(1);
            }
        }

        ll ans = 0;
        for (int i = 1; i < sz(cnt); i++) {
            if (cnt[i - 1] > cnt[i]) ans += cnt[i - 1] - cnt[i];
        }
        ans += cnt[sz(cnt) - 1];

        cout << ans << "\n";
    }

    return 0;
}
