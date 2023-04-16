#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using str = string;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t, ans;
    cin >> t;

    str s;
    while (t--) {
        cin >> s;
        ans = 0;

        if((int)s.size() == 1) {
            if(s[0] == '^') {
                cout << "1\n";
            } else {
                cout << "2\n";
            }

            continue;
        }

        for (int i = 0; i < (int) s.size(); i++) {
            if(s[i] == '_' && i == 0) {
                ans++;
            } else if (s[i] == '_' && i == (int) s.size() - 1) {
                ans++;
            } 

            if(i != (int) s.size() - 1 && s[i] == '_' && s[i + 1] != '^') {
                ans++;
            }
        }

        cout << ans << "\n";
    }
    return 0;
}
