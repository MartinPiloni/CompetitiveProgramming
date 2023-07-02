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
        int l, r;
        cin >> l >> r;
        
        int res = l; 
        int luck = 0;
        for (int i = l; i <= r; i++) {
            int j = i;
            int max_digit = 0, min_digit = 9, digit;
            while (j != 0) {
                digit = j % 10;
                if (digit < min_digit) {
                    min_digit = digit;
                }
                if (digit > max_digit) {
                    max_digit = digit;
                }
                j /= 10;
            }
            if ((max_digit - min_digit) > luck) {
                res = i;
                luck = max_digit - min_digit;
            }

            if (luck == 9) {
                break;
            }
        }
        cout << res << "\n";
    }

    return 0;
}
