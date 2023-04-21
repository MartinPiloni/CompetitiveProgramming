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
        str s;
        cin >> s;

        if (s[0] == '0') {
            cout << "0\n";
        } else {
            int ans = 1;
            for (int i = 0; i < (int) s.size(); i++) {
                if (s[i] == '?' && i == 0) ans *= 9;
                else if (s[i] == '?') ans *= 10;
            }
            cout << ans << "\n";
        }
    }

    return 0;
}
