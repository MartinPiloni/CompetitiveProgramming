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
    setIO("speeding");
    int n, m;
    cin >> n >> m;
    vector<int> road(100), journey(100);

    int a, b, start = 0, end = 0;
    for (int i = 0; i < n; i++) {
        cin >> a >> b;
        end += a;
        for (int j = start; j < end; j++) {
            road[j] = b;
        }
        start = end;
    }

    start = 0, end = 0;
    for (int i = 0; i < m; i++) {
        cin >> a >> b;
        end += a;
        for (int j = start; j < end; j++) {
            journey[j] = b;
        }
        start = end;
    }

    int ans = 0;
    for (int i = 0; i < 100; i++) {
        ans = max(ans, journey[i] - road[i]);
    }

    cout << ans << "\n";
    return 0;
}
