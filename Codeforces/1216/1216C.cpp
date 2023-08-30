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

    vector<ll> x(10), y(10);
    for (int i = 1; i < 7; i++) {
        cin >> x[i];
        cin >> y[i];
    }

    ll width = x[2] - x[1];
    ll length = y[2] - y[1];
    ll area = width * length;


    if (min(x[2], x[4]) - max(x[1], x[3]) > 0 && min(y[2], y[4]) - max(y[1], y[3]) > 0) {
        area -= (min(x[2], x[4]) - max(x[1], x[3])) * (min(y[2], y[4]) - max(y[1], y[3]));
    }

    if (min(x[2], x[6]) - max(x[1], x[5]) > 0 && min(y[2], y[6]) - max(y[1], y[5]) > 0) {
        area -= (min(x[2], x[6]) - max(x[1], x[5])) * (min(y[2], y[6]) - max(y[1], y[5]));
    }

    x[7] = max(x[1], x[3]);
    y[7] = max(y[1], y[3]);
    x[8] = min(x[2], x[4]);
    y[8] = min(y[2], y[4]);

    if (min(x[8], x[6]) - max(x[7], x[5]) > 0 && min(y[8], y[6]) - max(y[7], y[5]) > 0) {
        area += (min(x[8], x[6]) - max(x[7], x[5])) * (min(y[8], y[6]) - max(y[7], y[5]));
    }

    (area > 0 ? cout << "YES\n" : cout << "NO\n");
    return 0;
}
