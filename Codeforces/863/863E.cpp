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
    
    vector<pair<pair<int, int>, pair<int,int>>> v(2 * n);
    vector<int> end;
    map<int, int> start_at;
    int x, y;
    for (int i = 0; i < 2 * n; i += 2) {
        cin >> x >> y;
        x--;
        start_at[x]++;
        end.pb(y);
        v[i].fst = {x, 0};
        v[i].snd = {y, i / 2};
        v[i + 1].fst = {y, 1};
        v[i + 1].snd = {-x, i / 2};
    }
    sort(all(v));
    
    vector<bool> can(n);
    set<pair<int, int>> s;
    ll ans = -1;
    for (int i = 0; i < 2 * n; i++) {
        if (v[i].fst.snd == 0) {
            if (!s.empty() || start_at[v[i].fst.fst] > 1) can[v[i].snd.snd] = true;
            s.insert({end[v[i].snd.snd], v[i].snd.snd});
        } else {
            s.erase({v[i].fst.fst, v[i].snd.snd});
            if (can[v[i].snd.snd] && !s.empty()) {
                ans = v[i].snd.snd + 1;
                break;
            }
            if (sz(s) == 1) can[s.begin()->snd] = false;
        }
    }
    cout << ans << "\n";

    return 0;
}
