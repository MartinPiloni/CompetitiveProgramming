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

        vector<int> a(n), b(n), cnt_a(2 * n + 1, 0), cnt_b(2 * n + 1, 0);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
            if (cnt_a[a[i]] == 0) cnt_a[a[i]]++;
        }

        for(int i = 0; i < n; i++) {
            cin >> b[i];
            if (cnt_b[b[i]] == 0) cnt_b[b[i]]++;
        }

        int cnt = 1;
        for(int i = 0; i < n - 1; i++) {
            if (a[i] == a[i + 1]) cnt++;
            else {
                cnt_a[a[i]] = max(cnt_a[a[i]], cnt);
                cnt = 1;
            }

            if (i == n - 2) cnt_a[a[i]] = max(cnt_a[a[i]], cnt);
        }
        
        cnt = 1;
        for(int i = 0; i < n - 1; i++) {
            if (b[i] == b[i + 1]) cnt++;
            else {
                cnt_b[b[i]] = max(cnt_b[b[i]], cnt);
                cnt = 1;
            }

            if (i == n - 2) cnt_b[b[i]] = max(cnt_b[b[i]], cnt);
        }

        int ans = 0;
        for(int i = 1; i <= 2 * n; i++) {
            ans = max(ans, cnt_a[i] + cnt_b[i]);
        }

        cout << ans << "\n";
    }

    return 0;
}
