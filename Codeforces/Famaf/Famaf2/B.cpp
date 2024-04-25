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

        vector<pair<int, int>> v(n);
        for (int i = 0; i < n; i++) {
            cin >> v[i].first;
        }
        
        for (int i = 0; i < n; i++) {
            cin >> v[i].second;
        }
        sort(v.begin(), v.end());

        for (int i = 0; i < n; i++) {
            if (k >= v[i].first) {
                k += v[i].second;
            } else {
                break;
            }
        }

        cout << k << "\n";
    }

    return 0;
}
