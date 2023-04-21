#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using str = string;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int s, n;
    cin >> s >> n;

    vector<pair<int, int>> dragons(n);
    int a, b;
    for (int i = 0; i < n; i++) {
        cin >> a >> b;
        dragons[i] = make_pair(a, b);
    }
    sort(dragons.begin(), dragons.end());

    bool ans = true;
    for (int i = 0; i < n; i++) {
        if (s > dragons[i].first) {
            s += dragons[i].second;
        } else {
            ans = false;
            break;
        }
    }

    (ans ? cout << "YES\n" : cout << "NO\n");
    return 0;
}
