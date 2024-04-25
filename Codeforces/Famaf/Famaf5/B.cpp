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
        ll n;
        cin >> n;

        if (n == 1) {
            cout << "0\n";
            continue;
        }

        int ans = 0;
        while (n % 2 == 0 && n % 3 == 0) {
            ans++;
            n /= 6;
        }

        if (n % 2 == 0) {
            ans = -1;
        } else {
            while (n % 3 == 0) {
                ans += 2;
                n /= 3;
            }
        }

        if (n != 1) ans = -1;
        cout << ans << "\n";
    }

    return 0;
}
