#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using str = string;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    int l = 1, r = n, m, q;
    while (l != r - 1) {
        m = (l + r) / 2;
        cout << "? " << m << endl;
        cin >> q;

        if (q == 0) l = m;
        else r = m;
    }

    cout << "! " << l << endl;

    return 0;
}
