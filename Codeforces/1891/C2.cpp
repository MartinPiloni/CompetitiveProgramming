#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define fst first
#define snd second
#define sz(x) ((int)x.size())
#define all(x) x.begin(),x.end()

using ll = long long;
using str = string;

vector<ll> v;

bool can(ll m) {
    auto v2 = v;
    ll back = sz(v) - 1;
    ll moves = 0, cnt = 0, maxe = v2[back];

    for (int i = 0; i < sz(v2); i++) {
        if (v2[i] == 0) break;

        if (i == back) {
            if (v2[back] == 1 || cnt >= v2[back]) {moves++; continue;}

            v2[back] -= cnt;
            if (v2[back] & 1) moves += (v2[back] / 2) + 2;
            else moves += (v2[back] / 2) + 1;
        } else if (v2[i] + cnt >= maxe) {
            moves += maxe - cnt + 1;
            v2[i] -= maxe - cnt;
            cnt = 0;
            v2[back] = 0;
            back--;
            maxe = v2[back];

            if (v2[i] != 0) i--;
        } else {
            moves += v2[i];
            cnt += v2[i];
            v2[i] = 0;
        }
    }

    if (moves > m) return false;
    return true;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;

        v.resize(n);
        for (int i = 0; i < n; i++) cin >> v[i];
        sort(all(v));

        ll l = 0, r = 1e18, m;
        while (l <= r) {
            m = (l + r) / 2;
            if (can(m)) r = m - 1;
            else l = m + 1;
        }
        cout << r + 1 << "\n";
    }

    return 0;
}
