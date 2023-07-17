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
        ll n;
        cin >> n;
        vector<ll> v(n);
        for (int i = 0; i < n; i++) cin >> v[i];

        n = unique(v.begin(), v.end()) - v.begin();
        ll ans = n, i = 0, j = 1;
        while (j < n - 1) {
            if (abs(v[i] - v[j]) + abs(v[j] - v[j + 1]) == abs(v[i] - v[j + 1])) {
                ans--; j++;
            }
            else if (i == j - 1) {i++; j++;}
            else i++;
        }
        cout << ans << "\n";
    }

    return 0;
}
