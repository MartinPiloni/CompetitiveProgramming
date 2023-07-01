#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using str = string;

#define sz(x) int((x).size())

const int MAXN = 2e5 + 10;
const int MOD = 1e9 + 7;
int dp[MAXN][128];
int v[MAXN];
int n, k;

bool has_k_bits(int x, int k_b) {
    int cnt = 0; 
    
    while (x != 0) {
        if (x & 1) cnt++;
        x /= 2;
    }

    return cnt == k_b;
}

int f(int i, int x) {
    if (i == n) return (has_k_bits(x, k));

    int &r = dp[i][x];
    if (r != -1) return r;

    r = (f(i + 1, x) % MOD + f(i + 1, x & v[i]) % MOD) % MOD;

    return r;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    memset(dp, -1, sizeof dp);
    
    int t;
    cin >> t;
    while (t--) {
        cin >> n >> k;

        for (int i = 0; i < n; i++) {
            cin >> v[i];
        }

        cout << f(0, 127) << "\n";

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < 64; j++) {
                dp[i][j] = -1;
            }
            dp[i][127] = -1;
        }
    }

    return 0;
}
