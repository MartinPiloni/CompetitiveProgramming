#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using str = string;

#define sz(x) int((x).size())

void setIO(string name = "") {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    if ((int) name.size()) {
        freopen((name + ".in").c_str(), "r", stdin);
        freopen((name + ".out").c_str(), "w", stdout);
    }
}

int main() {
    setIO("cowsignal");

    int m, n, k;
    cin >> m >> n >> k;

    vector<str> v(m);
    for (int i = 0; i < m; i++) {
        cin >> v[i];
    }

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < k; j++) {
            for (int x = 0; x < n; x++) {
                for (int y = 0; y < k; y++) {
                    cout << v[i][x];
                }
            }
            cout << "\n";
        }
    }

    return 0;
}
