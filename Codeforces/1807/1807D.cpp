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
        int n, q;
        cin >> n >> q;
        vector<ll> v(n), ps(n + 1);
        for (int i = 0; i < n; i++) {
            cin >> v[i];
            ps[i + 1] = ps[i] + v[i];
        }
        
        ll l, r, k, sum = 0;
        while (q--) {
            cin >> l >> r >> k;
            l--; r--;
            sum = ps[l] + (r - l + 1) * k + ps[n] - ps[r + 1];
            (sum & 1 ? cout << "YES\n" : cout << "NO\n");
        }
    }

    return 0;
}
