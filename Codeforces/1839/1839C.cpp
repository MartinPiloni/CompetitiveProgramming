#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using str = string;

#define sz(x) int((x).size())

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        vector<int> v(n);
        for (int i = 0; i < n; i++) cin >> v[i];

        if (v[n - 1] == 1) {
            cout << "NO\n";
            continue;
        }

        vector<pair<int, int>> s;
        int cnt = 0;
        for (int i = 0; i < n; i++){
            if (v[i] == 1) cnt++;
            else if (cnt > 0 && v[i] != 1) {
                s.push_back({i - cnt, cnt});
                cnt = 0;
            }
        }

        cout << "YES\n";
        for (int i = n - 1; i >= 0; i--) {
            if (sz(s) > 0 && s.back().first == i) {
                cout << s.back().second << " ";
                s.pop_back();
            }
            else cout << "0 ";
        }
        cout << "\n";
    }

    return 0;
}
