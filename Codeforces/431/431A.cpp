#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using str = string;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    vector<int> v(4);
    for (int i = 0; i < 4; i++) cin >> v[i];

    str s;
    cin >> s;

    int ans = 0;
    for (int i = 0; i < (int)s.size(); i++) {
        ans += v[s[i] - '1'];
    }

    cout << ans << "\n";
    return 0;
}
