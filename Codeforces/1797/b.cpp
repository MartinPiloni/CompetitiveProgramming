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
        int n, k;
        cin >> n >> k;
        int pattern[n][n];
 
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> pattern[i][j];
            }
        }
 
        int ops = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (pattern[i][j] != pattern[n - i - 1][n - j - 1]) {
                    ops++;
                }
            }
        }
        ops /= 2; 

        if (((k - ops) % 2 != 0 && n % 2 == 0) || ops > k) {
            cout << "NO\n";
        } else {
            cout << "YES\n";
        }
    }
 
    return 0;
}
