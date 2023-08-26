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

    int n, m, n_e, n_s, s;
    cin >> n >> m >> n_s >> n_e >> s;

    vector<int> stairs(n_s);
    vector<int> elevators(n_e);
    for (int i = 0; i < n_s; i++) cin >> stairs[i];
    for (int i = 0; i < n_e; i++) cin >> elevators[i];
    sort(all(stairs));
    sort(all(elevators));
    
    int q;
    cin >> q;
    
    ll x1, y1, x2, y2;
    ll ans = 0;
    for (int i = 0; i < q; i++) {
        cin >> x1 >> y1 >> x2 >> y2;

        if (x1 == x2) {cout << abs(y2 - y1) << "\n"; continue;}

        ll lb_stair, lb_elevator, r_lb_stair, r_lb_elevator;
        if (sz(stairs) > 0) {
            lb_stair = *lower_bound(all(stairs), y1);
        } else {
            lb_stair = 1e9;
        }

        if (sz(elevators) > 0) {
            lb_elevator = *lower_bound(all(elevators), y1);
        } else {
            lb_elevator = 1e9;
        }

        if (sz(stairs) > 0 && lower_bound(all(stairs), y1) != stairs.begin()) {
            r_lb_stair = *(--lower_bound(all(stairs), y1));
        } else {
            r_lb_stair = 1e9;
        }

        if (sz(elevators) > 0 && lower_bound(all(elevators), y1) != elevators.begin()) {
            r_lb_elevator = *(--lower_bound(all(elevators), y1));
        } else {
            r_lb_elevator = 1e9;
        }

        ans = min({abs(y1 - lb_stair) + abs(x2 - x1) + abs(lb_stair - y2),
                   abs(y1 - lb_elevator) + abs(x2 - x1) / s + (!(abs(x2 - x1) % s == 0)) + abs(lb_elevator - y2),
                   abs(y1 - r_lb_stair) + abs(x2 - x1) + abs(r_lb_stair - y2),
                   abs(y1 - r_lb_elevator) + abs(x2 - x1) / s + (!(abs(x2 - x1) % s == 0)) + abs(r_lb_elevator - y2),
                   });

        cout << ans << "\n";
    }

    return 0;
}
