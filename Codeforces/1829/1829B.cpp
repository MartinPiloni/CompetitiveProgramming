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
        for(int i = 0; i < n; i++) {
            cin >> v[i];
        }

        int ans = 0, c = 0;
        for(int i = 0; i < n; i++) {
            if (v[i] == 0) c++;
            else {
                ans = max(ans, c);
                c = 0;
            }
        }
        
        ans = max(ans, c);
        cout << ans << "\n";
    }

    return 0;
}
