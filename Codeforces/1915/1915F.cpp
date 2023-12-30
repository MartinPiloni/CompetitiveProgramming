#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define fst first
#define snd second
#define sz(x) ((int)x.size())
#define all(x) x.begin(),x.end()

using ll = long long;
using str = string;

#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
typedef tree<pair<ll, ll>,null_type,less<pair<ll, ll>>,rb_tree_tag,tree_order_statistics_node_update> ordered_set;
// find_by_order(i) -> iterator to ith element
// order_of_key(k) -> position (int) of lower_bound of k

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<pair<pair<ll, ll>, ll>> v(2 * n);
        vector<ll> s_time(2 * n);
        for (int i = 0; i < 2 * n; i += 2) {
            int x, y;
            cin >> x >> y;

            s_time[i] = x;
            v[i].snd = 0;
            v[i].fst = {x, i};
            v[i + 1].snd = 1;
            v[i + 1].fst = {y, i};
        }
        sort(all(v));

        ll ans = 0;
        ordered_set s;
        for (int i = 0; i < 2 * n; i++) {
            if (v[i].snd == 0) {
                s.insert(v[i].fst);
            } else {
                ans += s.order_of_key(make_pair(s_time[v[i].fst.snd], v[i].fst.snd));
                s.erase(s.lower_bound(make_pair(s_time[v[i].fst.snd], v[i].fst.snd)));
            }
        }
        cout << ans << "\n";
    }

    return 0;
}
