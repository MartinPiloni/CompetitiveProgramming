#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using str = string;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    str s;
    cin >> s;

    ll ans = -1, curr;
    for (int j = 0; j < 2; j++) {    
        curr = 0;
        for (int i = 0; i < n; i++) {
            if (s[i] == 'o') {
                curr++;
            } else if (s[i] == '-') {
                if (curr > 0) ans = max(ans, curr);
                curr = 0;
            }
        }
        reverse(s.begin(), s.end());
    }
    cout << ans << "\n";

    return 0;
}
