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

        vector<int> a(n), b(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }

        for (int i = 0; i < n; i++) {
            cin >> b[i];
        }

        int l = 0, r = 0;
        for (int i = 0; i < n; i++) {
            if (a[i] != b[i]) {
                l = r = i;
                break;
            }
        }

        for (int i = l; i > 0; i--) {
            if (b[i - 1] <= b[i]) l--;
            else break;
        }

        for (int i = r; i < n - 1; i++) {
            if (b[i] <= b[i + 1]) r++;
            else break;
        }

        cout << l + 1 << " " << r + 1 << "\n";
    }

    return 0;
}
