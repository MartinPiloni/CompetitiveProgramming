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
        int n, s;
        cin >> n >> s;
        vector<int> v(n);
        int cnt = 0;
        for (int i = 0; i < n; i++) {
            cin >> v[i];
            if (v[i]) cnt++;
        }

        if (cnt < s) {cout << "-1\n"; continue;}
        else if (cnt == s) {cout << "0\n"; continue;}

        vector<int> l, r; 
        l.pb(0); r.pb(0);
        for (int i = 0; i < n; i++) {
            if (v[i] == 1) l.pb(i + 1); 
            if (cnt - sz(l) + 1 == s) break;
        }
        for (int i = n - 1; i >= 0; i--) {
            if (v[i] == 1) r.pb(n - i);
            if (cnt - sz(r) + 1 == s) break;
        }

        int ans = 1e9;
        for (int i = 0; i < cnt - s + 1; i++) ans = min(ans, l[sz(l) - 1 - i] + r[i]);
        cout << ans << "\n";
    }

    return 0;
}
