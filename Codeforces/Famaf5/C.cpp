#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using str = string;

#define sz(x) int((x).size())

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }
    sort(v.begin(), v.end());

    int x = 0, y = v.back();
    for (int i = n - 1; i >= 0; i--) {
        if (y % v[i] != 0 || v[i] == v[i - 1]) {
            x = v[i];
            break;
        }
    }

    cout << x << " " << y << "\n";
    return 0;
}
