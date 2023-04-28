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

        bool ok = false;
        for (int i = 0; i <= n; i++) {
            for (int j = i; j <= n; j++) {
                if (i * (i - 1) / 2 + j * (j - 1) / 2 == k && i + j == n) {
                    cout << "YES\n";
                    ok = true;

                    for (int l = 0; l < i; l++) {
                        cout << "1 ";
                    }

                    for (int l = 0; l < j; l++) {
                        cout << "-1 ";
                    }

                    cout << "\n";
                }
            }
            if (ok) break;
        } 

        if (!ok) cout << "NO\n";
    }

    return 0;
}
