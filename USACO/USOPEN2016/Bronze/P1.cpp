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
    setIO("diamond");

    int n, k;
    cin >> n >> k;
    vector<int> v(n);
    for (int i = 0; i < n; i++) cin >> v[i];
    sort(v.begin(), v.end());

    int cnt = 0, ans = 0;
    for (int i = 0; i < n; i++) {
        cnt = 1;
        for (int j = i + 1; j < n; j++) {
            if (abs(v[i] - v[j]) <= k) cnt++;
        }
        ans = max(ans, cnt);
    }
    cout << ans << "\n";

    return 0;
}
