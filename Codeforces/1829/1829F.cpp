#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using str = string;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;

        vector<int> g[n];
        int a, b;
        for (int i = 0; i < m; i++) {
            cin >> a >> b;
            a--; b--;
            g[a].push_back(b);
            g[b].push_back(a);
        }

        int x = 0, y = 0;
        for (int i = 0; i < n; i++) {
            if ((int) g[i].size() != 1) continue;

            y = (int) g[g[i][0]].size() - 1;
            for (auto v : g[g[i][0]]) {
                if ((int) g[v].size() > 1) {
                    x = (int)g[v].size();
                    break;
                }
            }
            break;
        }

        cout << x << " " << y << "\n";
    }
    return 0;
}
