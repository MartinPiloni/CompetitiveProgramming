#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using str = string;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, x;
    cin >> n;

    set<int> s;
    for (int i = 0; i < n; i++) {
        cin >> x;
        s.insert(x);
    }

    cout << s.size() << "\n";
    return 0;
}
