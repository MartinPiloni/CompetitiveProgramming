#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define fst first
#define snd second
#define sz(x) ((int)x.size())
#define all(x) x.begin(),x.end()

using ll = long long;
using str = string;

int square(int x) {
    return (x * x);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int r, d, n;
    cin >> r >> d >> n;

    vector<pair<pair<int, int>, int>> c(n);
    int x, y, z, ans = 0;
    for (int i = 0; i < n; i++) {
        cin >> x >> y >> z;
        c[i].fst.fst = x;
        c[i].fst.snd = y;
        c[i].snd = z;
        if (square(x) + square(y) <= square(r - z) && 
            square(x) + square(y) >= square(r - d + z)) ans++;
    }
    cout << ans << "\n";
    return 0;
}
