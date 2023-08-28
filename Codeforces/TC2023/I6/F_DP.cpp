#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define fst first
#define snd second
#define sz(x) ((int)x.size())
#define all(x) x.begin(),x.end()

using ll = long long;
using str = string;

const int MAXN = 110;
ll dp[MAXN][3];
str s;

ll f(int x, int c) {
    if (c == 3) return 1;
    if (x == sz(s)) return 0;

    ll &r = dp[x][c];
    if (r != -1) return r;

    r = 0;
    if ((c == 0 && s[x] == 'Q') || (c == 1 && s[x] == 'A') || (c == 2 && s[x] == 'Q')) {
        r += f(x + 1, c + 1) + f(x + 1, c);
    } else {
        r += f(x + 1, c);
    }

    return r;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    memset(dp, -1, sizeof dp);
    cin >> s;
    cout << f(0, 0) << "\n";

    return 0;
}
