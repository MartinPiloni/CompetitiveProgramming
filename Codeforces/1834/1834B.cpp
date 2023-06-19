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
        str l, r;
        cin >> l >> r;

        if (sz(l) < sz(r)) {
            str prefix = "";
            for (int i = 0; i < sz(r) - sz(l); i++) {
                prefix.append("0");
            }

            l = prefix + l;
        }

        int ans = 0;
        for (int i = 0; i < sz(l); i++) {
            if (l[i] != r[i]) {
                ans = r[i] - l[i];
                ans += (sz(l) - i - 1) * 9;
                break;
            }
        }

        cout << ans << "\n";
    }

    return 0;
}
