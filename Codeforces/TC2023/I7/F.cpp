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
        int n, m;
        cin >> n;

        vector<ll> v(n);
        ll v_odd = 0, v_even = 0, a_odd = 0, a_even = 0;
        for (int i = 0; i < n; i++) {
            cin >> v[i];
            if (v[i] & 1) v_odd++;
            else v_even++;
        }

        cin >> m;
        vector<ll> a(m);
        for (int i = 0; i < m; i++) {
            cin >> a[i];
            if (a[i] & 1) a_odd++;
            else a_even++;
        }

        cout << (v_even * a_even) + (v_odd * a_odd) << "\n";
    }

    return 0;
}
