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

    ll n, t, sum = 0;
    cin >> n >> t;
    vector<ll> v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
        sum += v[i];
        if (i != 0) v[i] += v[i - 1];
    }
    ll ans = lower_bound(v.begin(), v.end(), t % sum) - v.begin(); 
    cout << ans + 1 << " ";
    (ans == 0 ? cout << t % sum << "\n" : cout << (t % sum) - v[ans - 1] << "\n");
    return 0;
}
