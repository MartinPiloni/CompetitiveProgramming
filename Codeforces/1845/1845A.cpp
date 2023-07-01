#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using str = string;

#define fore(i,a,b) for(int i=a,ggdem=b;i<ggdem;++i)
#define sz(x) int((x).size())

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        int n, k, x;
        cin >> n >> k >> x;

        if (x != 1) {
            cout << "YES\n";
            cout << n << "\n";
            fore(i, 0, n) cout << 1 << " ";
            cout << "\n";
        } else if (n % 2 == 0 && k > 1) {
            cout << "YES\n";
            cout << n / 2 << "\n";
            for (int i = 0; i < n / 2; i++) {
                cout << 2 << " ";
            }
            cout << "\n";
        } else if (k >= 3) {
            cout << "YES\n";
            cout << n / 2 << "\n";
            for (int i = 0; i < (n / 2) - 1; i++) {
                cout << 2 << " ";
            }
            cout << 3 << "\n";
        } else {
            cout << "NO\n";
        }
    }
    return 0;
}
