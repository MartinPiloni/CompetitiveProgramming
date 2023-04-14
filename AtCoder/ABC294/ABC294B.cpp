#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using str = string;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int H, W;
    cin >> H >> W;

    int n;
    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            cin >> n;
            if (n == 0) cout << '.';
            else cout << char('A' + n - 1);
        }
        cout << "\n";
    }

    return 0;
}
