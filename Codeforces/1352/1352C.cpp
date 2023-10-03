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
        ll n, k;
        cin >> n >> k;

        ll ans = 0;
        if (k % (n - 1) == 0) ans = k / (n - 1) * n - 1;
        else ans = k / (n - 1) * n + k % (n - 1);
        cout << ans << "\n";
    }

    return 0;
}
