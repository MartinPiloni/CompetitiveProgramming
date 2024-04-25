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
        ll wa, fi;
        cin >> wa >> fi;

        int n;
        cin >> n;
        vector<int> v(n);
        ll sum = 0;
        for (int i = 0; i < n; i++) {
            cin >> v[i];
            sum += v[i];
        }

        vector<vector<bool>> dp(n, vector<bool>(1e6));
        vector<vector<bool>> vis(n, vector<bool>(1e6));
        auto f = [&](int m, int s, auto&& self) -> bool {
            if ((m == n && s != 0) || s < 0) return false;
            if (s == 0) return true;

            auto r = dp[m][s];
            if(vis[m][s]) return dp[m][s];

            r = (self(m + 1, s, self) || self(m + 1, s - v[m], self));
            vis[m][s] = 1;

            return r;
        };

        auto can = [&](int time) -> bool {
            bool ans = false;
            for (int i = 0; i <= sum; i++) {
                if (f(0, i, f) && ((time * wa >= i && time * fi >= sum - i) || 
                                   (time * fi >= i && time * wa >= sum - i))) {
                    ans = true;
                    break;
                }
            }
            return ans;
        };

        int l = 1, r = 1e6, m;
        while (l <= r) {
            m = (l + r) / 2;
            if (can(m)) r = m - 1;
            else l = m + 1;
        }
        cout << l << "\n";
    }


    return 0;
}
