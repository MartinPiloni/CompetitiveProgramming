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
        vector<int> v(n);
        
        int mi = 1e9, ma = 0;
        for (int i = 0; i < n; i++) {
            cin >> v[i];
            mi = min(mi, v[i]);
            ma = max(ma, v[i]);
        }

        ll min_pos = find(v.begin(), v.end(), mi) - v.begin();
        ll max_pos = find(v.begin(), v.end(), ma) - v.begin();

        ll ans = 1e9, c = 4;
        if (min_pos + 1 < ans) {c = 0; ans = min_pos + 1;}
        if (max_pos + 1 < ans) {c = 1; ans = max_pos + 1;}
        if (n - min_pos < ans) {c = 2; ans = n - min_pos;}
        if (n - max_pos < ans) {c = 3; ans = n - max_pos;}

        if (c == 0) {
            ans += min(max_pos - min_pos, n - max_pos);
        } else if (c == 1) {
            ans += min(min_pos - max_pos, n - min_pos);
        } else if (c == 2) {
            ans += min(max_pos + 1, min_pos - max_pos);
        } else {
            ans += min(min_pos + 1, max_pos - min_pos);
        }

        cout << ans << "\n";
    }

    return 0;
}
