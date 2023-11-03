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

    int t;
    cin >> t;
    while (t--) {
        ll n, x, y;
        str a, b;
        cin >> n >> x >> y >> a >> b;

        ll cnt = 0;
        for (int i = 0; i < n; i++) {
            if (a[i] != b[i]) cnt++;
        }

        if (cnt == 0) {cout << "0\n"; continue;}
        else if (cnt & 1) {cout << "-1\n"; continue;}

        ll l = 0, r = n - 1;
        if (cnt == 2) {
            while (a[l] == b[l]) l++;
            while (a[r] == b[r]) r--;

            if (l + 1 == r) cout << min(x, y * 2) << "\n";
            else cout << y << "\n";
        } else {
            cout << y * cnt / 2 << "\n";
        }
    }

    return 0;
}
