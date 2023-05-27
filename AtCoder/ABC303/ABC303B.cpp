#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using str = string;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;
    
    vector<set<int>> neighbors(n);

    int p, last = 0;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            cin >> p;
            p--;
            if (j == 0) last = p;
            else { 
                neighbors[p].insert(last);
                neighbors[last].insert(p);
                last = p;
            }
        }
    }

    int ans = 0;
    for (int i = 0; i < n; i++) {
        if ((int)neighbors[i].size() < n - 1) ans += (n - 1) - (int)neighbors[i].size();
    }

    cout << ans / 2 << "\n";

    return 0;
}
