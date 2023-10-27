#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define fst first
#define snd second
#define sz(x) ((int)x.size())
#define all(x) x.begin(),x.end()

using ll = long long;
using str = string;

const int MAXN = 1e5 + 10;
const int m = 1e9 + 7;
int dp_l[MAXN][26], dp_r[MAXN][26];
str s;
ll n;

ll exp_pow(ll b, ll e) {
    if(e == 0) return 1;
    
    ll x;
    if(e % 2 == 0) {
        x = exp_pow(b, e / 2) % m;
        return (x * x) % m;
    } else {
        x = exp_pow(b, (e - 1) / 2) % m;
        return (((x * x) % m) * b) % m;
    }

}

ll inv(ll a) {
    return exp_pow(a, m - 2);
}
    
int f_l(int x, int c) {
    if (x == -1) return 0;

    int &r = dp_l[x][c];
    if (r != -1) return r;

    if (s[x] - '0' > c) r = 1 + f_l(x - 1, c);
    else r = f_l(x - 1, c);

    return r;
}

int f_r(int x, int c) {
    if (x == sz(s)) return 0;

    int &r = dp_r[x][c];
    if (r != -1) return r;

    if (s[x] - '0' > c) r = 1 + f_r(x + 1, c);
    else r = f_r(x + 1, c);

    return r;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    memset(dp_l, -1, sizeof dp_l);
    memset(dp_r, -1, sizeof dp_r);

    cin >> s >> n;
    ll ans = 0;
    ll l_const = ((((n % m) * ((n + 1) % m)) % m) * inv(2) % m) % m;
    ll r_const = (((((n - 1) % m) * (n % m)) % m) * inv(2) % m) % m;
    for (int i = 0; i < sz(s); i++) {
        ans = (ans % m + (l_const * f_l(i, s[i] - '0') % m) % m + (r_const * f_r(i, s[i] - '0') % m) % m) % m;
    }
    cout << ans % m << "\n";

    return 0;
}