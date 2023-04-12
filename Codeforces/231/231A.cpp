#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using str = string;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n;
    cin >> n;

    int a, b, c, ans = 0;
    for (int i = 0; i < n; i++) {
        cin >> a >> b >> c;
        if (a + b + c > 1) ans++;
    }

    cout << ans << "\n";
    return 0;
}
