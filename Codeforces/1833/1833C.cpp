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
        vector<int> v(n);
        for (int i = 0; i < n; i++) {
            cin >> v[i];
        }
        sort(v.begin(), v.end());
        if (v[0] & 1) cout << "YES\n";
        else {
            bool ok = true;
            for (int i = 0; i < n; i++) {
                if (v[i] & 1) {
                    ok = false;
                    break;
                }
            }
            cout << (ok ? "YES\n" : "NO\n");
        }
    }

    return 0;
}
