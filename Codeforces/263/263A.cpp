#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using str = string;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, ans = 0;
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            cin >> n;
            if (n == 1) {
                ans = abs(i + 1 - 3) + abs(j + 1 - 3);
            } 
        }
    }

    cout << ans << "\n";
    return 0;
}
