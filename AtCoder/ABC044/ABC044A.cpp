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

    ll n, k, x, y;
    cin >> n >> k >> x >> y;
    if (n <= k) {
        cout << n * x << "\n";
    } else {
        cout << k * x + (n - k) * y << "\n";
    }
    return 0;
}
