#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using str = string;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    vector<vector<int>> cnt(n, vector<int>(n));
    int p, last;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            cin >> p;
            p--;

            if (j != 0) {
                cnt[p][last]++; cnt[last][p]++;
            }
            last = p;
        }
    }

    int ans = 0;
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (cnt[i][j] == 0) ans++;
        }
    }
    
    cout << ans << "\n";
    return 0;
}
