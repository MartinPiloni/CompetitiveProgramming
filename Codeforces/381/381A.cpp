#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using str = string;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<int> c(n);
    for (int i = 0; i < n; i++) {
        cin >> c[i];
    }

    int turn = 0, d = 0, s = 0, h;
    while(c.empty() == false) {
        h = max(c[0], c.back());
        if (c[0] > c.back()) {
            c.erase(c.begin());
        } else {
            c.pop_back();
        }
        
        (turn % 2 == 0 ? s += h : d += h);
        turn++;
    }

    cout << s << " " << d << "\n";
    return 0;
}
