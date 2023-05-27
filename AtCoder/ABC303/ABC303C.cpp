#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using str = string;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m, h, k;
    str s;

    // n = moves to complete, m = items available to recover hp
    // h = health, k = consume items if health is < k
    // s = path
    cin >> n >> m >> h >> k >> s;
    set<pair<int, int>> items;
    
    int x, y;
    for (int i = 0; i < m; i++) {
        cin >> x >> y;
        items.insert(make_pair(x, y));
    }

    pair<int, int> pos = {0, 0};
    bool ok = true;
    for (int i = 0; i < n; i++) {
        if (s[i] == 'R') pos.first++;
        else if (s[i] == 'L') pos.first--;
        else if (s[i] == 'U') pos.second++;
        else if (s[i] == 'D') pos.second--;

        h--;
        if (h < 0) {
            ok = false;
            break;
        } else if (items.find(pos) != items.end() && h < k) {
            items.erase(pos);
            h = k;
        }
    }

    cout << (ok ? "Yes\n" : "No\n");
    return 0;
}
