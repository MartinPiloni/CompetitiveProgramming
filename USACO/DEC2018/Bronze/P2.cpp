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
    setIO("blist");

    int n;
    cin >> n;
    vector<int> buckets(1000);

    int s, t, b;
    for (int i = 0; i < n; i++) {
        cin >> s >> t >> b;
        s--; t--;
        for (int j = s; j <= t; j++) {
            buckets[j] += b;
        }
    }

    int ans = 0;
    for (int i = 0; i < 1000; i++) {
        ans = max(ans, buckets[i]);
    }

    cout << ans << "\n";
    return 0;
}
