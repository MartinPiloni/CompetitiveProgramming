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

bool area[2010][2010];

void paint_area(int x1, int x2, int y1, int y2) {
    for (int i = x1; i < x2; i++) {
        for (int j = y1; j < y2; j++) {
            area[i + 1000][j + 1000] = true;
        }
    }
}

void block_area(int x1, int x2, int y1, int y2) {
    for (int i = x1; i < x2; i++) {
        for (int j = y1; j < y2; j++) {
            area[i + 1000][j + 1000] = false;
        }
    }
}

int main() {
    setIO("billboard");

    int x1, y1, x2, y2;
    cin >> x1 >> y1 >> x2 >> y2;
    paint_area(x1, x2, y1, y2);
    cin >> x1 >> y1 >> x2 >> y2;
    paint_area(x1, x2, y1, y2);
    cin >> x1 >> y1 >> x2 >> y2;
    block_area(x1, x2, y1, y2);

    ll ans = 0;
    for (int i = 0; i < 2010; i++) {
        for (int j = 0; j < 2010; j++) {
            if (area[i][j]) ans++;
        }
    }
    cout << ans << "\n";

    return 0;
}
