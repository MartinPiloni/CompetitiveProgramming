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
        int n, k;
        cin >> n >> k;

        vector<string> v(n);
        for(int i = 0; i < n; i++) {
            cin >> v[i];
        }

        int ans = 1;
        for(int i = 1; i < n; i++) {
            if (v[i] == v[0]) ans++;
        }

        cout << ans << "\n";
    }

    return 0;
}
