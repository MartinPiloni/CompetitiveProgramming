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
        int cnt_n = 0, cnt_p = 0;
        for (int i = 0; i < n; i++) {
            cin >> v[i];
            if (v[i] == 1) cnt_p++;
            else cnt_n++;
        }

        int ans = 0;
        while (cnt_n > cnt_p) {
            cnt_n--;
            cnt_p++;
            ans++;
        }

        if (cnt_n & 1) ans++;
        cout << ans << "\n";
    }

    return 0;
}
