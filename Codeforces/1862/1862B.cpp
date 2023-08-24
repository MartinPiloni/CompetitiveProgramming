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
        vector<int> v(n), ans;
        for (int i = 0; i < n; i++) cin >> v[i];
        ans.pb(v[0]);
        for (int i = 1; i < n; i++) {
            if (v[i] >= v[i - 1]) ans.pb(v[i]);
            else {ans.pb(v[i]); ans.pb(v[i]);}
        }

        cout << sz(ans) << "\n";
        for (int i = 0; i < sz(ans); i++) cout << ans[i] << " \n"[i == sz(ans) - 1];
    }

    return 0;
}
