#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using str = string;

const int MAX_N = 2 * 1e5 + 10;
int n;
int a[MAX_N], dp[MAX_N];

bool valid(int r) {
    return 0 <= r && r <= n;
}

int score(int x) {
    if (x == n) return 0;

    int &r = dp[x];
    if (r != -1) return r;

    r = a[x];
    if (valid(x + a[x])) {
        r += score(x + a[x]);
    }

    return r;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        cin >> n;
        for (int i = 0; i < n; i++) cin >> a[i];
        memset(dp, -1, sizeof dp);

        int ans = 0;
        for (int i = 0; i < n; i++) {
            ans = max(ans, score(i));
        }
        cout << ans << "\n";
    }

    return 0;
}
