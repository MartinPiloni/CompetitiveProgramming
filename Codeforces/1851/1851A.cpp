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
        ll n, m, k, h;
        cin >> n >> m >> k >> h;
        vector<int> v(n);
        for (int i = 0; i < n; i++) cin >> v[i];
        ll ans = 0;
        for (int i = 0; i < n; i++) {
            if (h != v[i] && abs(h - v[i]) % k == 0 && abs(h - v[i]) / k < m) ans++;
        }
        cout << ans << "\n";
    }

    return 0;
}
