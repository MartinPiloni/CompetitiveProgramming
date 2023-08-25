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

    ll n, m, a, b;
    cin >> n >> m;
    a = n; b = m;

    ll f2_n = 0, f2_m = 0, f3_n = 0, f3_m = 0;
    while (n % 2 == 0) {n /= 2; f2_n++;}
    while (n % 3 == 0) {n /= 3; f3_n++;}
    while (m % 2 == 0) {m /= 2; f2_m++;}
    while (m % 3 == 0) {m /= 3; f3_m++;}
    for (int i = 0; i < f2_m - f2_n; i++) a *= 2;
    for (int i = 0; i < f3_m - f3_n; i++) a *= 3;

    if (f2_n > f2_m || f3_n > f3_m || a != b) cout << "-1\n";
    else cout << f2_m - f2_n + f3_m - f3_n << "\n";

    return 0;
}
