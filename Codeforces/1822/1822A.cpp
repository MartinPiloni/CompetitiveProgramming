#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using str = string;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int q;
    cin >> q;
    while(q--) {
        int n, t;
        cin >> n >> t;

        vector<pair<pair<int, int>, int>> v(n);
        for (int i = 0; i < n; i++) {
            cin >> v[i].first.second;
            v[i].second = i;
        }
        
        for (int i = 0; i < n; i++) {
            cin >> v[i].first.first;
            v[i].first.first *= -1;
        }
        sort(v.begin(), v.end());

        bool ok = false;
        for (int i = 0; i < n; i++) {
            if (v[i].first.second + v[i].second <= t) {
                cout << v[i].second + 1 << "\n";
                ok = true;
                break;
            }
        }

        if (!ok) {
            cout << "-1\n";
        }

    }
    return 0;
}
