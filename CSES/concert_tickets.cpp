#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using str = string;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m, c;
    cin >> n >> m;

    multiset<int> tickets;
    for (int i = 0; i < n; i++) {
        cin >> c;
        tickets.insert(c);
    }

    int t;
    for (int i = 0; i < m; i++) {
        cin >> t;
        auto it = tickets.upper_bound(t);
        if (it != tickets.begin()) {
            cout << *--it << "\n";
            tickets.erase(it);
        } else {
            cout << "-1\n";
        }
    }

    return 0;
}
