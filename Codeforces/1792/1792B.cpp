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
    while(t--) {
        ll a, b, c, d; 
        cin >> a >> b >> c >> d;
        
        ll ans;
        if (a == 0) ans = 1;
        else {
            ans = a + min(b, c) * 2;
            ll left = abs(b - c) + d;
            if (left > a) ans += a + 1;
            else ans += left; 
        }

        cout << ans << "\n";
    }
    return 0;
}
