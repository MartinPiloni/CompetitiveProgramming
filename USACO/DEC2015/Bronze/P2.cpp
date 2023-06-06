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
    vector<pair<int, int>> road(n), journey(m);
    
    int a, b;
    for (int i = 0; i < n; i++) {
        cin >> a >> b;
        road[i] = {a, b};
    }

    for (int i = 0; i < m; i++) {
        cin >> a >> b;
        journey[i] = {a, b};
    }

    int pos = journey[0].first, r_pos = road[0].first, i = 0, j = 0, ans = 0;
    while(i != n && j != m) {
        ans = max(ans, journey[j].second - road[i].second);

        if (r_pos > pos) {
            j++;
            pos += journey[j].first;
        } else if (pos > r_pos) {
            i++;
            r_pos += road[i].first;
        } else {
            i++; 
            j++;
            pos += journey[j].first;
            r_pos += road[i].first;
        }
    }

    cout << ans << "\n";
    return 0;
}
