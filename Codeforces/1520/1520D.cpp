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
        vector<ll> v(n);
        map<ll, ll> m;
        for (int i = 0; i < n; i++) cin >> v[i];
        for (int i = 0; i < n; i++) m[v[i] - i + 1]++;
        ll ans = 0;
        for (auto p : m) ans += (p.snd - 1) * p.snd / 2;
        cout << ans << "\n";
    }

    return 0;
}
