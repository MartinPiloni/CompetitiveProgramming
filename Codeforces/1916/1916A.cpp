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
        int n, k;
        cin >> n >> k;
        
        ll x = 2023, in;
        bool ok = true;
        for (int i = 0; i < n; i++) {
            cin >> in;
            if ((x % in) != 0) ok = false;
            else x /= in;
        }

        if (!ok) {
            cout << "NO\n";
            continue;
        }

        vector<int> ans;
        for (int i = 0; i < k; i++) {
            if (x == 2023) ans.pb(2023), x /= 2023;
            else if (x >= 289) ans.pb(289), x /= 289;
            else if (x >= 119) ans.pb(119), x /= 119;
            else if (x >= 17) ans.pb(17), x /= 17;
            else if (x >= 7) ans.pb(7), x /= 7;
            else if (x == 1) ans.pb(1);
        }
        if (x != 1) ok = false;
        (ok ? cout << "YES\n" : cout << "NO\n");
        for (auto e : ans) cout << e << " ";
        cout << "\n";
        
    }

    return 0;
}
