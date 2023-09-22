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
        vector<str> g(10);
        int n = 10;
        for (int i = 0; i < n; i++) cin >> g[i];

        ll ans = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (g[i][j] == 'X') {
                    if (i == 0 || j == 0 || i == n - 1|| j == n - 1) ans++;
                    else if (i == 1 || j == 1 || i == n - 2|| j == n - 2) ans += 2;
                    else if (i == 2 || j == 2 || i == n - 3|| j == n - 3) ans += 3;
                    else if (i == 3 || j == 3 || i == n - 4|| j == n - 4) ans += 4;
                    else if (i == 4 || j == 4 || i == n - 5|| j == n - 5) ans += 5;
                }
            }
        }
        cout << ans << '\n';
    }

    return 0;
}
