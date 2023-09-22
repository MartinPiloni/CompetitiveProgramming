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

        ll ans = 0, p = 0;
        for (int i = 0; i < n; i++) {
            p = 1;
            v[i]++;
            for (int j = 0; j < n; j++) {
                p *= v[j];
            }
            v[i]--;
            ans = max(ans, p);
        }
        cout << ans << "\n";
    }

    return 0;
}
