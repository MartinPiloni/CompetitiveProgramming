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

    ll x;
    cin >> x;
    str ans = "";
    while (x != 0) {
        ll d = min(9 - x % 10, x % 10);
        ans += to_string(d);
        x /= 10;
    }
    reverse(all(ans));
    if (ans[0] == '0') ans[0] = '9';
    cout << ans << "\n";


    return 0;
}
