#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using str = string;

#define sz(x) int((x).size())

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        vector<pair<ll, ll>> v(n);

        ll a, b;
        for (int i = 0; i < n; i++) {
            cin >> a >> b;
            v[i] = {a, -b};
        }
        sort(v.begin(), v.end());
        reverse(v.begin(), v.end());

        vector<ll> on;
        ll ans = 0, cnt = 0, i = 0;
        while(sz(v) != 0) {
            cnt++;
            ans += -1 * v.back().second;
            on.push_back(v.back().first);
            v.pop_back();
            
            while (sz(v) != 0 && cnt >= v.back().first) {
                v.pop_back();
            }
            
            int e = 0;
            while (i < sz(on) && cnt >= on[i]) {
                i++;
                e++;
            }
            cnt -= e;
        }

        cout << ans << "\n";
    }

    return 0;
}
