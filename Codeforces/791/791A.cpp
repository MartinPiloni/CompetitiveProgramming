#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using str = string;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int a, b, ans = 0;
    cin >> a >> b;

    while (a <= b) {
        a *= 3;
        b *= 2;
        ans++;
    }

    cout << ans << "\n";
    return 0;
}
