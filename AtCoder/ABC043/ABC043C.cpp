#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define fst first
#define snd second
#define sz(x) ((int)x.size())
#define all(x) x.begin(),x.end()

using ll = long long;
using str = string;

ll sqr(ll x) {
    return x * x;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    vector<ll> v(n);
    for (int i = 0; i < n; i++) cin >> v[i];
    sort(all(v));
    ll ans = 1e9, sum = 0;
    for (ll i = v[0]; i <= v[n - 1]; i++){
        sum = 0;
        for (int j = 0; j < n; j++) {
            sum += sqr(v[j] - i);
        }
        ans = min(ans, sum);
    }
    cout << ans << "\n";
    return 0;
}
