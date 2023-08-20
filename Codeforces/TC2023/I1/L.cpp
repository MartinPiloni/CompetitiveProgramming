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

    int n;
    cin >> n;

    map<ll, int> freq;
    set<ll> d;
    ll x = n, t, s, in;
    for (int i = 0; i < n; i++) {
        cin >> t >> s;
        if (t == 1) {
            for (int j = 0; j < s; j++) {
                cin >> in;
                freq[in]++;
            }
        } else {
            x--;
            for (int j = 0; j < s; j++) {
                cin >> in;
                d.insert(in);
                freq[in]--;
            }
        }
    }

    if (x == 0) cout << (ll)1e18 - (ll)sz(d) << "\n";
    else {
        int ans = 0;
        for (auto e : freq) {
            if (e.second == x) ans++;
        }
        cout << ans << "\n";
    }

    return 0;
}
