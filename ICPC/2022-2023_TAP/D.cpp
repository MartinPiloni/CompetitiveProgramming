#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define fst first
#define snd second
#define sz(x) ((int)x.size())
#define all(x) x.begin(),x.end()

using ll = long long;
using str = string;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, x, y, end_x, end_y;
    cin >> n >> x >> y;
    end_x = end_y = 1 << (n - 1);

    int cnt = 0;
    while (x != end_x && y != end_y) {
        if (x < end_x && y < end_y) {
            x *= 2;
            y *= 2;
        } else if (x < end_x && y > end_y) {
            x *= 2;
            y = y * 2 - (1 << n);
        } else if (x > end_x && y < end_y) {
            x = x * 2 - (1 << n);
            y *= 2;
        } else {
            x = x * 2 - (1 << n);
            y = y * 2 - (1 << n);
        }
        cnt++;
    }
    cout << cnt << "\n";

    return 0;
}
