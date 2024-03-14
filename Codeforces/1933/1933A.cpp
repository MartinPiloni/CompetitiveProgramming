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

        ll ans = 0;
        ll x;
        for (int i = 0; i < n; i++) {
            cin >> x;
            ans += abs(x);
        }
        cout << ans << "\n";
    }

    return 0;
}
