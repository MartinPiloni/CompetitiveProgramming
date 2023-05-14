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

    int ans = 0;
    for (int i = 0; i < n - 1; i++) {
        if (s[i] == s[i + 1]) ans++;
    }

    cout << ans << "\n";
    return 0;
}
