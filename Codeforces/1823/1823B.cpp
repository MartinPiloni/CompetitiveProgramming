#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using str = string;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        
        vector<int> v(n);
        vector<int> bad;
        for (int i = 0; i < n; i++) {
            cin >> v[i];
            if (v[i] % k != (i + 1) % k) bad.push_back(v[i]);
        }

        if ((int) bad.size() == 0) cout << "0\n";
        else if ((int) bad.size() == 2) cout << "1\n";
        else cout << "-1\n";
    }

    return 0;
}
