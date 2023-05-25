#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using str = string;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--){
        int n;
        cin >> n;
        
        vector<int> v(n);
        for (int i = 0; i < n; i++) {
            cin >> v[i];
        }

        int l = 0, r = 1e9, mid;
        while (l <= r) {
            mid = (l + r) / 2;

            int s; 
            auto sum = v;
            for (int i = n - 1; i >= 2; i--) {
                if (sum[i] < mid) break;

                s = min(v[i], sum[i] - mid) / 3;
                sum[i] -= 3 * s;
                sum[i - 1] += s;
                sum[i - 2] += 2 * s;
            }

            int m = 1e9;
            for (int i = 0; i < n; i++) {
                m = min(sum[i], m);
            }

            if (m >= mid) l = mid + 1;
            else r = mid - 1;
        }
        cout << r << "\n";
    }
    return 0;
}
