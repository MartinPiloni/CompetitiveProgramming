#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using str = string;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<int> a(n);
    vector<int> ones_index;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        if (a[i] == 1) ones_index.push_back(i);
    }

    ll ans  = 1;
    if ((int) ones_index.size() == 0) {
        cout << "0\n";
    } else {
        for (auto it = ones_index.begin(); it < ones_index.end(); it++) {
            auto j = it + 1;
            if (j != ones_index.end()) {
                ans *= (*j - *it);
            }
        }
        cout << ans << "\n";
    }

    return 0;
}
