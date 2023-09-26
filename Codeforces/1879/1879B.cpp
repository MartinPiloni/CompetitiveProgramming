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
        vector<ll> r(n), c(n);
        ll min_r = 1e9, min_c = 1e9, s_r = 0, s_c = 0;
        for (int i = 0; i < n; i++) {
            cin >> r[i];
            min_r = min(min_r, r[i]);
            s_r += r[i];
        }
        for (int i = 0; i < n; i++) {
            cin >> c[i];
            min_c = min(min_c, c[i]);
            s_c += c[i];
        }
        cout << min(s_c + (min_r * n), s_r + (min_c * n)) << "\n";
    }

    return 0;
}
