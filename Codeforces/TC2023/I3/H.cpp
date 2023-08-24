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

    ll a, b;
    cin >> a >> b;
    while(a != 0 && b != 0) {
        if (a >= 2 * b) a = a % (2 * b);
        else if (b >= 2 * a) b = b % (2 * a);
        else break;
    }

    cout << a << " " << b << "\n";
    return 0;
}
