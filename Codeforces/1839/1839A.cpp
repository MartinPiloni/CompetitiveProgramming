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
        int n, k;
        cin >> n >> k;

        vector<bool> ones(100, 0);
        int cnt = 0, cnt2 = 0, ans = 0;
        for (int i = 0; i < n / 2; i++) {
            if (((i + 1) + k - 1) / k > cnt) {
                cnt++;
                ans++;
                ones[i] = true; 
            }
        }

        for (int i = n - 1; i > n / 2; i--) {
            if (((n - i) + k - 1) / k > cnt2) {
                cnt2++;
                ans++;
                ones[i] = true; 
            }
        }

        bool ok = true;
        int i = n / 2;
        while (ones[i] != 1) {
            if (((i + 1) + k - 1) / k > cnt) {
                ok = false;
                break;
            }
            i++;
        }
        
        if (!ok) ans++;
        cout << ans << "\n";
    }
    return 0;
}

