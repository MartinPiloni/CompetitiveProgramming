#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using str = string;

#define sz(x) int((x).size())

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while(t--) {
        int n; str s;
        cin >> n >> s;

        str ans = "";
        char ec;
        bool e = false;
        for (int i = 0; i < n; i++) {
            if (!e) {
                ans += s[i];
                e = true;
                ec = s[i];
            } else if (e && s[i] == ec) {
                e = false;
            }
        }

        cout << ans << "\n";
    }

    return 0;
}
