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
        ll n, k, q;
        cin >> n >> k >> q;
        vector<int> v(n);
        for (int i = 0; i < n; i++) {
            cin >> v[i];
        }

        
        int cnt = 0;
        vector<int> s;
        for (int i = 0; i < n; i++) {
            if (v[i] <= q) cnt++;
            else if (v[i] > q && cnt >= k) {
                s.push_back(cnt);
                cnt = 0;
            } else {
                cnt = 0;
            }
        }
        if (cnt >= k) s.push_back(cnt);

        ll ans = 0;
        for (auto e : s) {
            for (int i = e; i >= 1; i--) {
                ans += max(0LL, i - k + 1);
                if (i - k + 1 < 0) break;
            }
        }

        cout << ans << "\n";
    }
    return 0;
}
