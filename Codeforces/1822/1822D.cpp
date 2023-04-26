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
        int n;
        cin >> n;

        if (n == 1) {
            cout << "1\n";
        } else if (n % 2 == 1) {
            cout << "-1\n";
        } else {
            cout << n << " ";
            cout << n - 1 << " ";
            
            int e = 2, o = n - 3;
            for (int i = 0; i < n - 2; i++) {
                if (i % 2 == 0) {
                    cout << e << " ";
                    e += 2;
                } else {
                    cout << o << " ";
                    o -= 2;
                }
            }

            cout << "\n";
        }
    }

    return 0;
}
