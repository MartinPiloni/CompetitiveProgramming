#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(int i=a;i<b;++i)
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
        fore(i, 0, n) cin >> v[i];
        vector<ll> dist;
        fore(i, 0, n - 1) dist.pb(abs(v[i] - v[i + 1]));
        sort(all(dist));
        fore(i, 0, k - 1) dist.pop_back();
        ll ans = 0;
        fore(i, 0, sz(dist)) ans += dist[i];
        cout << ans << "\n";
    }
        
    return 0;
}
