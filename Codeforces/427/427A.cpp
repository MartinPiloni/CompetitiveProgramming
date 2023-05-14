#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using str = string;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    ll ans = 0, a = 0, e;
    for (int i = 0; i < n; i++) {
        cin >> e;
        if (e == -1 && a == 0) ans++;
        else if (e == -1) a--;
        else a += e;
    }

    cout << ans << "\n";

    return 0;
}
