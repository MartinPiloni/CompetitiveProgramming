#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define fst first
#define snd second
#define sz(x) ((int)x.size())
#define all(x) x.begin(),x.end()

using ll = long long;
using str = string;

const int MAXN = 4e3 + 10;
int dp[MAXN][MAXN];
int n, a, b, c;

int f(int x, int cap) {
    if (cap == 0) return 0;
    else if ((x == n && cap != 0) || (cap < 0)) return -1e9;

    int &r = dp[x][cap];
    if (r != -1) return r;
    
    r = max({1 + f(x + 1, cap - a), 1 + f(x + 1, cap - b), 1 + f(x + 1, cap - c)});
    return r;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    memset(dp, -1, sizeof dp);
    cin >> n >> a >> b >> c;
    cout << f(0, n) << "\n";

    return 0;
}
