#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using str = string;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<pair<int, int>> v(n);
    int s = 0;
    for (int i = 0; i < n; i++) {
        if (i == 0) {
            v[i].first = 1;
        } else { 
            v[i].first = v[i - 1].second + 1;
        }
        cin >> v[i].second;
        s += v[i].second;
        v[i].second = s;
    }

    int m;
    cin >> m;

    vector<int> a(m);
    for (int i = 0; i < m; i++) {
        cin >> a[i];
    }

    for (int i = 0; i < m; i++) {
        int l = 0, r = n - 1, mid;
        while (l <= r) {
            mid = (l + r) / 2;
            if (a[i] > v[mid].first && a[i] > v[mid].second) {
                l = mid + 1;
            } else if (a[i] < v[mid].first && a[i] < v[mid].second) {
                r = mid - 1;
            } else {
                cout << mid + 1 << "\n";
                break;
            }
        }
    }


    return 0;
}
