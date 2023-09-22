#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define fst first
#define snd second
#define sz(x) ((int)x.size())
#define all(x) x.begin(),x.end()

using ll = long long;
using str = string;

const int MAXN = 2e5 + 10;
ll v[MAXN];
ll n, x;

bool can(ll m) {
    ll cnt = 0;
    for (int i = 0; i < n; i++) {
        if (v[i] < m) {
            cnt += m - v[i];
        }
    }

    if (cnt > x) return false;
    else return true;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        cin >> n >> x;
        for (int i = 0; i < n; i++) cin >> v[i];

        ll l = 1, r = 2e9, m; 
        while (l <= r) {
            m = (l + r) / 2;
            if (can(m)) {
                l = m + 1;
            } else {
                r = m - 1;
            }
        }
        cout << l - 1 << "\n";
    }

    return 0;
}
