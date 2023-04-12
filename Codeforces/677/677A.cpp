#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using str = string;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, h;
    cin >> n >> h;

    int p, ans = 0;
    for (int i = 0; i < n; i++) {
        cin >> p;
        if (p > h) ans += 2;
        else ans++;
    }

    cout << ans << "\n";
    return 0;
}
