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
        ll n, c;
        cin >> n >> c;
        vector<pair<ll, int>> v(n);
        vector<ll> sum(n);
        for (int i = 0; i < n; i++) {
            cin >> v[i].fst;
            sum[i] = v[i].fst;
            v[i].fst = (v[i].fst - (i + 1) * c) * -1;
            v[i].snd = i;
        }
        sort(all(v));

        bool f = true;
        for (int i = 0; i < n; i++) {
            if (v[i].snd == 0) continue;

            if (v[i].fst * -1 + sum[0] >= 0) {
                sum[0] += sum[v[i].snd];
            } else {
                f = false;
            }
        }
        (f ? cout << "YES\n" : cout << "NO\n");
    }

    return 0;
}
