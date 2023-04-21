#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using str = string;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        str s;
        cin >> s;

        int ans = 1e9;
        for (char c = 'a'; c < 'z'; c++) {
            int count = 0;
            int max_i = 0;
            int sum = 0;
            for (int j = 0; j < (int) s.size(); j++) {
                if (s[j] != c) {
                    count++;
                } else {
                    while (count != 0) {
                        count /= 2;
                        sum++;
                    }
                    max_i = max(max_i, sum);
                    sum = 0;
                }
            }

            while (count != 0) {
                count /= 2;
                sum++;
            }

            max_i = max(max_i, sum);
            ans = min(ans, max_i);
        }
        cout << ans << "\n";
    }

    return 0;
}
