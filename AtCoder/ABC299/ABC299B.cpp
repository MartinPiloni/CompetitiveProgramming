#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using str = string;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, t, c;
    cin >> n >> t;
    vector<pair <pair<int, int>, int>> v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i].first.first;
        v[i].second = i;

        if (i == 0) c = v[i].first.first;
    }

    for (int i = 0; i < n; i++) {
        cin >> v[i].first.second;
        v[i].first.second *= -1;
    }

    sort(v.begin(), v.end());
    bool b = false;
    for (int i = 0; i < n; i++) {
        if (v[i].first.first == t) {
            cout << v[i].second + 1 << "\n";
            b = true;
            break;
        }
    }

    if (!b) {
        for (int i = 0; i < n; i++) {
            if (v[i].first.first == c) {
                cout << v[i].second + 1 << "\n";
                break;
            }
        }
    }

    return 0;
}
