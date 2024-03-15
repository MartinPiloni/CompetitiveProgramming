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

        map<ll, ll> need;
        ll ans = 0;
        for (int i = 0; i < n; i++) {
            ll x;
            cin >> x;

            if (need[x]) need[x]--;
            else {
                ans++;
                need[x ^ ((1LL << 31) - 1)]++;
            }
        }
        cout << ans << "\n";
    }

    return 0;
}
