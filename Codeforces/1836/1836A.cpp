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

        vector<int> v(100, 0);
        
        int x;
        for (int i = 0; i < n; i++) {
            cin >> x;
            v[x]++;
        }

        bool ok = true;
        for (int i = 0; i < 99; i++) {
            if (v[i] < v[i + 1]) {
                ok = false;
                break;
            }
        }

        (ok ? cout << "YES\n" : cout << "NO\n");
    }



    return 0;
}
