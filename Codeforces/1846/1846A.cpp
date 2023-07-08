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

        vector<pair<int, int>> v(n);
        int x, y;
        for (int i = 0; i < n; i++) {
            cin >> x >> y;
            v[i] = {x, y};
        }

        int ans = 0;
        for (int i = 0; i < n; i++) {
            if (v[i].fst > v[i].snd) ans++;
        }
        cout << ans << "\n";
    }

    return 0;
}
