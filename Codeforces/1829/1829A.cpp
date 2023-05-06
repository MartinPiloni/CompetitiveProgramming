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
        str c, s = "codeforces";
        cin >> c;

        int ans = 0;
        for (int i = 0; i < (int)c.size(); i++) {
            if (c[i] != s[i]) ans++;
        }

        cout << ans << "\n";
    }
    return 0;
}
