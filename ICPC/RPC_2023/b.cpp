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

    int n; cin >> n;
    ll c, x, y, z;
    cin >> c >> x >> y >> z;
    ll time = x + y;
    cout << "1\n";
    for (int i = 1; i < n; i++) {
        cin >> c >> x >> y >> z;
        if (time <= x + z) {
            cout << c << "\n";
            time = max(time + y, x + y);
        }
    }

    return 0;
}
