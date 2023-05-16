#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using str = string;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;

        if (n & 1) {
            for (int i = 1; i <= n; i++) {
                cout << i << " ";
            }
        } else {
            for (int i = 1; i <= n; i++) {
                cout << 2 * i << " ";
            }
        }

        cout << "\n";
    }

    return 0;
}
