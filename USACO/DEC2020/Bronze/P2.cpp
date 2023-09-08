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
    setIO();

    int n;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++) cin >> v[i];

    int ans = n;
    long double avg = 0;
    for (int i = 0; i < n; i++) {
        avg = v[i];
        for (int j = i + 1; j < n; j++) {
            avg = (avg * (j - i) + v[j]) / (j - i + 1);
            for (int k = i; k <= j; k++) {
                if (abs(v[k] - avg) < 1e-3) {
                    ans++;
                    break;
                }
            }
        }
    }
    cout << ans << "\n";

    return 0;
}
