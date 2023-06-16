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
        ll n, k;
        cin >> n >> k;

        if (k >= 30) cout << n + 1 << "\n";
        else cout << min(n + 1, (ll)pow(2, k)) << "\n";
    }

    return 0;
}
