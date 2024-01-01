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
        int cnt = 0;
        for (int i = 0; i < n; i++) {
            cin >> v[i];
            if (v[i] == 1) cnt++;
        }
        ll ans = n;
        ans -= cnt / 2;
        cout << ans << "\n";
    }

    return 0;
}
