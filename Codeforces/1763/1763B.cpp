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
        ll n, k;
        cin >> n >> k;
        vector<pair<ll, ll>> v(n);
        for (int i = 0; i < n; i++) cin >> v[i].snd;
        for (int i = 0; i < n; i++) cin >> v[i].fst;
        sort(all(v));

        ll i = 0, d = 0;
        while (i != n && k > 0) {
            d += k;

            if (v[i].snd - d <= 0) {
                while (i != n && v[i].snd - d <= 0) {
                    i++;
                }

                if (i == n) break;
            }

            k -= v[i].fst;
        }

        (i == n ? cout << "YES\n" : cout << "NO\n");
    }

    return 0;
}
