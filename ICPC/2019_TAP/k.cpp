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
    vector<vector<ll>> v;
    
    char b_t;
    ll l, r, b;
    for (int i = 0; i < n; i++) {
        cin >> b_t >> l >> r; 
        if (b_t == 'D') b = 0;
        else b = 1;
        v.pb({l, r, b, 0});
        v.pb({r, l, b, 1});
    }
    sort(all(v));

    multiset<ll> s_d, s_j;
    ll ans = 0;
    for (int i = 0; i < sz(v); i++) {
        if (v[i][3] == 0 && v[i][2] == 0) s_d.insert(v[i][0]);
        else if (v[i][3] == 0 && v[i][2] == 1) s_j.insert(v[i][0]);
        else if (v[i][3] == 1 && v[i][2] == 0) {
            if (!empty(s_j)) {
                ans = max(ans, v[i][0] - max(*s_j.begin(), v[i][1]));
            }
            auto it = s_d.find(v[i][1]);
            s_d.erase(it);
        }
        else if (v[i][3] == 1 && v[i][2] == 1) {
            if (!empty(s_d)) {
                ans = max(ans, v[i][0] - max(*s_d.begin(), v[i][1]));
            }
            auto it = s_j.find(v[i][1]);
            s_j.erase(it);
        }
    }
    cout << ans << "\n";

    return 0;
}
