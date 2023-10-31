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
        sort(all(v));

        ll back = n - 1;
        ll moves = 0, cnt = 0, maxe = v[back];

        for (int i = 0; i < n; i++) {
            if (v[i] == 0) break;

            if (i == back) {
                if (v[back] == 1 || cnt >= v[back]) {moves++; continue;}

                v[back] -= cnt;
                if (v[back] & 1) moves += (v[back] / 2) + 2;
                else moves += (v[back] / 2) + 1;
            } else if (v[i] + cnt >= maxe) {
                moves += maxe - cnt + 1;
                v[i] -= maxe - cnt;
                cnt = 0;
                v[back] = 0;
                back--;
                maxe = v[back];

                if (v[i] != 0) i--;
            } else {
                moves += v[i];
                cnt += v[i];
                v[i] = 0;
            }
        }
        cout << moves << "\n";
    }

    return 0;
}
