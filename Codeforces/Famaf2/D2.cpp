#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using str = string;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<int> v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i];

        if (i != 0) {
            v[i] += v[i-1];
        }
    }

    int m, q;
    cin >> m;
    for (int i = 0; i < m; i++) {
        cin >> q;
        cout << lower_bound(v.begin(), v.end(), q) - v.begin() + 1 << "\n";
    }

    return 0;
}
