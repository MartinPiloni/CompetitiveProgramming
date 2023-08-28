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

    ll k, n, w;
    cin >> k >> n >> w;

    w = w * (w + 1) / 2;
    if (n > k * w) cout << "0\n";
    else cout << k * w - n << "\n";

    return 0;
}
