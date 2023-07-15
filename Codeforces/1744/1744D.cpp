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
        for (int i = 0; i < n; i++) cin >> v[i];

        int cnt = 0;
        for (auto x : v) {
            int y = x;
            while (y % 2 == 0) {
                cnt++;
                y /= 2;
            }
        }

        if (cnt >= n) {cout << "0\n"; continue;}

        vector<int> d;
        for (int i = 2; i <= n; i += 2) {
            int j = i, div = 0;
            while (j % 2 == 0) {
                div++;
                j /= 2;
            }
            d.pb(-div);
        }
        sort(all(d));

        int ans = 0, i = 0;
        while (cnt < n && i < sz(d)) {
            cnt += d[i] * -1;
            ans++;
            i++;
        }

        (cnt < n ? cout << "-1\n" : cout << ans << "\n");
    }

    return 0;
}
