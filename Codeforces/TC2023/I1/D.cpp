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

    ll n, xs, ys, xe, ye;
    cin >> n >> xs >> ys >> xe >> ye;
    ll ans = 0;
    if (abs(xs- xe) + abs(ys - ye) == 0) {
        ans = n / 2;
    } else if (abs(xs - xe) + abs(ys - ye) <= n) {
        n -= abs(xs - xe) + abs(ys - ye); 
        ans = (n / 2) + 1;
    }
    cout << ans << "\n";

    return 0;
}
