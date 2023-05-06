#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using str = string;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;

        vector<pair<int, string>> v(n);
        for (int i = 0; i < n; i++) {
            cin >> v[i].first;
            cin >> v[i].second;
        }
        sort(v.begin(), v.end());

        int s1 = int(1e9), s2 = int(1e9);
        for (int i = 0; i < n; i++) {
            if (v[i].second == "10" && s1 == int(1e9)) s1 = v[i].first;
            if (v[i].second == "01" && s2 == int(1e9)) s2 = v[i].first;
            if (v[i].second == "11" && s1 + s2 > v[i].first) {
                s1 = v[i].first / 2;
                s2 = (v[i].first & 1 ? v[i].first / 2 + 1 : v[i].first / 2);
            }
        }
        
        cout << (s1 != int(1e9) && s2 != int(1e9) ? s1 + s2 : -1) << "\n";
    }

    return 0;
}
