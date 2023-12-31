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
    
    vector<vector<int>> v;
    vector<int> end;
    map<int, int> start_at;
    int x, y;
    for (int i = 0; i < n; i++) {
        cin >> x >> y;
        x--;
        v.pb({x, 0, y, i});
        v.pb({y, 1, -x, i});
        start_at[x]++;
        end.pb(y);
    }
    sort(all(v));
    
    vector<bool> can(n);
    set<pair<int, int>> s;
    ll ans = -1;
    for (int i = 0; i < sz(v); i++) {
        if (v[i][1] == 0) {
            if (!s.empty() || start_at[v[i][0]] > 1) can[v[i][3]] = true;
            s.insert({end[v[i][3]], v[i][3]});
        } else {
            s.erase({v[i][0], v[i][3]});
            if (can[v[i][3]] && !s.empty()) {
                ans = v[i][3] + 1;
                break;
            }
            if (sz(s) == 1) can[s.begin()->snd] = false;
        }
    }
    cout << ans << "\n";

    return 0;
}
