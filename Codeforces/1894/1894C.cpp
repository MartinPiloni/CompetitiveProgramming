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
        int n, k;
        cin >> n >> k;
        vector<ll> v(n);
        for (int i = 0; i < n; i++) cin >> v[i];

        vector<bool> vis(2e5 + 10);
        ll j = n - 1;
        bool ok = true;
        for (int i = 0; i < k; i++) {
            if (v[j] > n) {
                ok = false;
                break;
            } else if (vis[j]) {
                break;
            }

            vis[j] = true;
            j = (n + j - v[j]) % n;
        }

        (ok ? cout << "YES\n" : cout << "NO\n");
    }

    return 0;
}

// 2 3 2 1

// 2 3
// 2 3 2
// 2 3 2 1
// 2 3 1
// 2 2
// 2 3 2 1
