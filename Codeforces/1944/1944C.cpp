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
        map<ll, ll> freq;
        for (int i = 0; i < n; i++) {
            cin >> v[i];
            freq[v[i]]++;
        }
        sort(all(v));

        if (freq[0] == 0) {
            cout << "0\n";
            continue;
        }

        ll r = 0;
        for (int i = 1; i < n; i++) {
            if (v[i] != v[i - 1] && v[i] != v[i - 1] + 1) {
                r = v[i - 1];
                break;
            }

            if (i == n - 1) r = v[n - 1];
        }

        vector<ll> freq_1;
        for (auto e : freq) {
            if (e.snd == 1) freq_1.pb(e.fst);
        }

        ll ans = 0;
        if (sz(freq_1) < 2 || (sz(freq_1) >= 2 && freq_1[1] > r)) ans = r + 1;
        else if (sz(freq_1) >= 2 && freq_1[1] <= r) ans = freq_1[1];
        cout << ans << "\n";
    }

    return 0;
}
