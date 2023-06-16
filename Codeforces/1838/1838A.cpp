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
        
        bool f = false;
        for (int i = 0; i < n; i++) {
            cin >> v[i];
            if (v[i] < 0 && !f) {
                cout << v[i] << "\n";
                f = true;
            }
        }
        if (f) continue;

        sort(v.begin(), v.end());
        cout << v[n - 1] << "\n";
    }

    return 0;
}
