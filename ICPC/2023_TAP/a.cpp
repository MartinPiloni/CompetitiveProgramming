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

    int n, m;
    cin >> n >> m;
    vector<ll> v(n), p;
    for (int i = 0; i < n; i++) cin >> v[i];

    int x;
    for (int i = 0; i < m; i++) {
        cin >> x;
        
        if (i == 0) p.pb(x);
        else if (x < p.back()) p.pb(x);
    }

    ll s = 0;
    for (int i = 0; i < n; i++) {
        s = v[i];

        while (true) {
            auto it = lower_bound(all(p), s, greater<int>());
            if (it == p.end()) {
                break;
            } else {
                s -= *it * (s / *it);
            }
        }

        cout << s << " ";
    }
    cout << "\n";

    return 0;
}
