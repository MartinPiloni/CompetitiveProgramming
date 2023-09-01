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
        int k, n, m;
        cin >> k >> n >> m;
        vector<int> v(n), a(m);
        for (int i = 0; i < n; i++) cin >> v[i];
        for (int i = 0; i < m; i++) cin >> a[i];

        int i = 0, j = 0, lines = k;
        bool can = true;
        vector<int> ans;
        while (i != n || j != m) {
            if (i != n && v[i] == 0) {ans.pb(0); lines++; i++;}
            else if (j != m && a[j] == 0) {ans.pb(0); lines++; j++;}
            else if (i != n && v[i] <= lines) {ans.pb(v[i]); i++;}
            else if (j != m && a[j] <= lines) {ans.pb(a[j]); j++;}
            else {can = false; break;}
        }
        
        if (can) {
            for (int in = 0; in < sz(ans); in++) cout << ans[in] << " \n"[in == sz(ans) - 1];
        } else {
            cout << "-1\n";
        }
    }

    return 0;
}
