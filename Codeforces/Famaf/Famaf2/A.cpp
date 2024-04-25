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
        int a, b, c;
        cin >> a >> b >> c;
        int m = min(a, min(b, c));
        int n = max(a, max(b, c));

        if (a != m && a != n) {
            cout << a << "\n";
        } else if (b != m && b != n) {
            cout << b << "\n";
        } else {
            cout << c << "\n";
        }
    }

    return 0;
}
