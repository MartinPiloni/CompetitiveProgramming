#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using str = string;

#define sz(x) int((x).size())

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t;
    cin >> t;
    while(t--) {
        int n, m;
        cin >> n >> m;

        vector<vector<int>> g(n, vector<int>(m));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                g[i][j] = i * m + j + 1;
            }
        }
        
        if (m % 2 == 0) {
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < m; j++) {
                    cout << g[i][j] << " ";
                }
                cout << "\n";
            }
        } else {
            for (int i = n - 1; i >= 0; i--) {
                if (g[i][0] % 2 == 0) continue;
                for (int j = 0; j < m; j++) {
                    cout << g[i][j] << " ";
                }
                cout << "\n";
            }
            
            for (int i = n - 1; i >= 0; i--) {
                if (g[i][0] & 1) continue;
                for (int j = 0; j < m; j++) {
                    cout << g[i][j] << " ";
                }
                cout << "\n";
            }
        }

        if (t != 0) cout << "\n";
    }

    return 0;
}
