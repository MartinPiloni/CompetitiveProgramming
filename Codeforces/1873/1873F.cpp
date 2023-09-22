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
        vector<ll> v(n), h(n);
        for(int i = 0; i < n; i++) cin >> v[i];
        for(int i = 0; i < n; i++) cin >> h[i];

        set<ll> s;
        ll ans = 0, sum = 0;
        for (int i = 0; i < n; i++) {
            //cout << "i: " << i << endl;
            //cout << "sum: " << sum << " k: " << k << endl;
            //for (auto e : s) {
            //    cout << e << " ";
            //}
            //cout << endl;

            if (s.empty() && v[i] <= k) {
                s.insert(i);
                sum += v[i];
            } else if (i > 0 && h[i - 1] % h[i] == 0 && sum + v[i] <= k) {
                s.insert(i);
                sum += v[i];
            } else if (i > 0 && h[i - 1] % h[i] == 0 && v[i] <= k) {
                while (sum + v[i] > k && !s.empty()) {
                    auto it = s.begin();
                    sum -= v[*it];
                    s.erase(s.begin());
                }

                sum += v[i];
                s.insert(i);
            } else if (v[i] <= k){
                s.clear();
                s.insert(i);
                sum = v[i];
            } else {
                s.clear();
                sum = 0;
            }
            ans = max(ans, (ll)sz(s));
        }
        cout << ans << endl;

    }

    return 0;
}
