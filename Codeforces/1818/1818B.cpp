#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using str = string;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >>t;
    while(t--) {
        int n;
        cin >> n;

        if (n == 1) {
            cout << "1\n";
            continue;
        }
        
        if ((n * (n + 1) / 2) % n == 0) cout << "-1\n";
        else {
            for (int i = 0; i < n; i++) {
                if (i & 1) cout << i << " ";
                else cout << i + 2 << " ";
            }
            cout << "\n";
        }
    }

    return 0;
}
