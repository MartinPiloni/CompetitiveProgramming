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

        bool ok = true;
        if (n >= 4) {
            ok &= v[2] <= v[3];
        }

        if (n >= 5) {
            for (int i = (1 << 2) + 1; i < min(n, (1 << 3)); i++) {
                ok &= v[i - 1] <= v[i];
            }
        }

        if (n >= 8) {
            for (int i = (1 << 3) + 1; i < min(n, (1 << 4)); i++) {
                ok &= v[i - 1] <= v[i];
            }
        }

        if (n >= 16) {
            for (int i = (1 << 4) + 1; i < min(n, (1 << 5)); i++) {
                ok &= v[i - 1] <= v[i];
            }
        }

        (ok ? cout << "YES\n" : cout << "NO\n");

    }

    return 0;
}
