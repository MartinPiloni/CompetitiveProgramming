#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using str = string;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    int ans = 0;
    int curr[5] = {100, 20, 10, 5, 1};
    for (int i = 0; i < 5; i++) {
        if (n / curr[i] != 0) {
            ans += n / curr[i];
            n = n % curr[i];
        }
    }

    cout << ans << "\n";

    return 0;
}
