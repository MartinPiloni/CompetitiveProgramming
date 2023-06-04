#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using str = string;

#define sz(x) int((x).size())

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int l = 1, r = 1e6, m;
    str q;
    while (l != r) {
        m = (l + r + 1) / 2;
        cout << m << endl;

        cin >> q;
        if (q == ">=") l = m;
        else r = m - 1;
    }

    cout << "! " << l << endl;

    return 0;
}
