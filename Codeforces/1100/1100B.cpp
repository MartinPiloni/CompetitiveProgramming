#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using str = string;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    int q;
    map<int, int> dict;
    for (int i = 0; i < m; i++) {
        cin >> q;
        dict[q]++;

        if ((int) dict.size() == n) {
            cout << 1;
            for (int j = 1; j <= n; j++) {
                if (dict[j] == 1) {
                    dict.erase(j);
                } else {
                    dict[j]--;
                }
            }
        } else {
            cout << 0;
        }
    }

    cout << "\n";
    return 0;
}
