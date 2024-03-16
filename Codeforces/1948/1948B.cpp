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
        vector<str> v(n);
        for (int i = 0; i < n; i++) cin >> v[i];

        bool can_split = true;
        char max_seen = '0';


        vector<int> ans;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < sz(v[i]); j++) {
                if (can_split && v[i][j] >= max_seen) {
                    max_seen = v[i][j];
                } else {
                    can_split = false;
                    ans.pb(stoi(v[i]));
                }
            }

            if (can_split) {
                for (int j = 0; j < sz(v[i]); j++) {
                    ans.pb(int(v[i][j] - '0'));
                }
            }
        }

        bool ok = true;
        for (int i = 1; i < sz(ans); i++) {
            ok &= ans[i - 1] <= ans[i];
        }
        (ok ? cout << "YES\n" : cout << "NO\n");
    }

    return 0;
}
