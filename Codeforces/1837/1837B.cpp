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
        str s;
        cin >> n >> s;

        int ans = 0, cnt = 1;
        char last = s[0];
        for (int i = 1; i < n; i++) {
            if (s[i] == last) {
                cnt++;
            } else {
                ans = max(ans, cnt);
                cnt = 1;
                last = s[i];
            }
        }

        ans = max(ans, cnt);
        cout << ans + 1 << "\n";
    }

    return 0;
}
