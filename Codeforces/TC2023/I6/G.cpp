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

    ll a, b, x, y, z;
    cin >> a >> b >> x >> y >> z;

    a -= x * 2;
    a -= y;
    b -= y;
    b -= 3 * z;

    ll ans = 0;
    if (a < 0) ans += -a;
    if (b < 0) ans += -b;
    cout << ans << "\n";


    return 0;
}
