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

    ll x, y;
    cin >> x >> y;
    ll dist = sqrt(x * x + y * y);
    if (dist * dist == x * x + y * y) {cout << "black\n"; return 0;}

    if (x * y > 0 && dist & 1) cout << "white\n";
    else if (x * y > 0) cout << "black\n";
    else if (x * y < 0 && dist & 1) cout << "black\n";
    else cout << "white\n";

    return 0;
}
