#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using str = string;

#define sz(x) int((x).size())

ll n, k;

ll pow(ll b, ll e) {
    if (e == 0) return 1;

    ll x;
    if (e % 2 == 0) {
        x = pow(b, e / 2);
        return (x * x);
    } else {
        x = pow(b, (e - 1) / 2);
        return ((x * x) * b);
    }
}

bool can(ll v) {
    ll s = 0, i = 0, a = 0;
    while(1) {
        a = v / pow(k, i);
        if (a == 0) break;

        s += a;
        i++;
    }    

    if (s >= n) return true;
    else return false;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> k;

    ll l = 1, r = n, m;
    while (l <= r) {
        m = (l + r) / 2;

        if (can(m)) r = m - 1;
        else l = m + 1;
    }

    cout << r + 1 << "\n";

    return 0;
}
