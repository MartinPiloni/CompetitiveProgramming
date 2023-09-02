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
    setIO("billboard");

    int x1, y1, x2, y2, x3, y3, x4, y4;
    cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3 >> x4 >> y4;

    int width = x2 - x1;
    int length = y2 - y1;
    int area = width * length;

    if (x3 <= x1 && x2 <= x4 && !(y1 < y3 && y4 < y2)) {
        area -= width * max(min(y2, y4) - max(y1, y3), 0);
    } else if (y3 <= y1 && y2 <= y4 && !(x1 < x3 && x4 < x3)) {
        area -= length * max(min(x2, x4) - max(x1, x3), 0); 
    }
    cout << area << "\n";

    return 0;
}
