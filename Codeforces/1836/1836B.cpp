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
        ll n, k, g;
        cin >> n >> k >> g;

        ll silver_coins = k * g;
        ll c = (g + 2 - 1) / 2;

        if (n * (c - 1) > silver_coins) {
            cout << k * g << "\n";
            continue;
        }

        ll saved = (c - 1) * (n - 1);
        silver_coins -= saved;
        if ((silver_coins % g) >= c) {
            saved -= g - (silver_coins % g);
        } else {
            saved += (silver_coins % g);
        }

        cout << saved << "\n";
    }

    return 0;
}
