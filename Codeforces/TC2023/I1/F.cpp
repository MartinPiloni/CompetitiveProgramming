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

    int n, i_r, o_r;
    cin >> n >> o_r >> i_r;

    long double c = 2 * acos(-1); 
    long double h = sin(c/(2 * n)) * i_r;
    long double ans = (o_r * h / 2) * (2 * n);
    cout << setprecision(10) << ans << "\n";

    return 0;
}
