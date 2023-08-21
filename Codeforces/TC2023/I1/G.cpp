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

    int n, m;
    cin >> n >> m;
    
    vector<ll> a(n), b(m);
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i < m; i++) {cin >> b[i]; b[i] *= -1;}
    sort(all(a));
    sort(all(b));

    ll ans = 0;
    for (int i = 0; i < min(n, m); i++) {
        if (a[i] < b[i] * -1) ans += b[i] * -1 - a[i];
        else break;
    }
    cout << ans << "\n";

    return 0;
}
