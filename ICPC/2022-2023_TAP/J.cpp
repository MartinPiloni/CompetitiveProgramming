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

    vector<int> v(11, 4);
    v[10] = 16;
    int n, x, y, jp = 0, mp = 0;
    cin >> n >> x >> y;
    if (x > 10) x = 10;
    if (y > 10) y = 10;
    jp = x + y;
    v[x]--;
    v[y]--;

    cin >> x >> y;
    if (x > 10) x = 10;
    if (y > 10) y = 10;
    mp = x + y;
    v[x]--;
    v[y]--;
    for (int i = 0; i < n; i++) {
        cin >> x;
        if (x > 10) x = 10;
        jp += x;
        mp += x;
        v[x]--;
    }

    if (mp >= jp) {
        if (23 - mp > 10) {
            cout << "-1\n";
        } else if (v[23 - mp] == 0) {
            cout << "-1\n";
        } else {
            cout << 23 - mp << "\n";
        }
    } else {
        bool f = false;
        for (int i = min(23 - jp + 1, 11); i <= min(23 - mp, 10); i++) {
            if (v[i] != 0) {
                cout << i << "\n";
                f = true;
                break;
            }
        }

        if (!f) cout << "-1\n";
    } 

    return 0;
}
