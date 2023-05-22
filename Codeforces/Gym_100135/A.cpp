#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using str = string;

const int MAX_N = 105;
int a[MAX_N], dp[MAX_N];
int n;

void setIO(string name = "") {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    if ((int) name.size()) {
        freopen((name + ".in").c_str(), "r", stdin);
        freopen((name + ".out").c_str(), "w", stdout);
    }
}

int climb(int x) {
    if (x == n) return a[x];
    else if (x == n - 1) return a[x] + a[x + 1];

    int &r = dp[x];
    if (r != -1) return r;

    r = a[x];
    r += max(climb(x + 1), climb(x + 2));

    return r;
}

int main() {
    setIO("ladder");

    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i];

    memset(dp, -1, sizeof dp);

    cout << climb(0) << "\n";

    return 0;
}
