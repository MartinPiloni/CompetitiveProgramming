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

    long double y, x, r; cin >> y >> x >> r;
    x = abs(x);
    if (x <= r) cout << 0 << '\n';
    else {
        long double b = y;
        long double a = (b/x)*(b/x);
        long double c = -(b*b/a - r*r/a - r*r);
        if (c < 0) cout << -1 << '\n';
        else {
            c = 2*sqrt(c);
            long double d = (2*b/a - c < 0)? (2*b/a + c)/(2 + 2/a) : (2*b/a - c)/(2 + 2/a);
            long double pi = acos(-1);
            cout << setprecision(20);
            cout << 180*acos(sqrt(r*r - d*d)/r)/pi << '\n';
        }
    }

    return 0;
}