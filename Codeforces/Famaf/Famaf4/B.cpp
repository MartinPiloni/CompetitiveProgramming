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
        vector<int> v(n);
        for (int i = 0; i < n; i++) cin >> v[i];
        int j = 0;
        for (int i = 0; i < n; i++) {
            if (i & 1) {
                cout << v[n - 1 - j] << " ";
                j++;
            }
            else cout << v[j] << " ";
        }
        cout << "\n";
    }
    return 0;
}
