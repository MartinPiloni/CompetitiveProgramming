#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using str = string;

int n, m;

int from(int i) {
    return i / m;
}

int to(int i) {
    return i % m;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while(t--) {
        cin >> n >> m;

        vector<int> g[n * m];
        vector<bool> vis(n * m, 1);
        int grid[n][m];
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> grid[i][j];
            }
        }

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] != 0) vis[i * m + j] = 0;
            
                if (j != 0 && grid[i][j] != 0 && grid[i][j - 1] != 0) {
                    g[i * m + j].push_back(i * m + j - 1);
                    g[i * m + j - 1].push_back(i * m + j);
                }
            
                if (i != 0 && grid[i][j] != 0 && grid[i - 1][j] != 0) {
                    g[i * m + j].push_back((i - 1) * m + j);
                    g[(i - 1) * m + j].push_back(i * m + j);
                }
            }
        }

        int ans = 0, s = 0;
        for (int i = 0; i < n * m; i++) {
            if (!vis[i]) {
                s = grid[from(i)][to(i)];

                queue<int> q;
                q.push(i);
                vis[i] = true;
                while(!q.empty()) {
                    int node = q.front(); q.pop();
                    for (auto j : g[node]) {
                        if (vis[j]) continue;
                        s += grid[from(j)][to(j)];
                        q.push(j);
                        vis[j] = true;
                    }
                }

                ans = max(ans, s);
            }
        }

        cout << ans << "\n";
    }

    return 0;
}
