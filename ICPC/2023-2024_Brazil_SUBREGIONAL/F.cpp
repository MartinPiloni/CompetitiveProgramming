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

    ll d, c, r;
    cin >> d >> c >> r;
    
    vector<int> v(c);
    ll ans = 0, in;
    for (int i = 0; i < c; i++) {
        cin >> v[i];
    }
    for (int i = 0; i < r; i++) {
        cin >> in; 
        d += in;
        ans++;
    }

    for(int i = 0; i < c; i++) {
        if (d >= v[i]) {
            ans++;
            d -= v[i];
        } else {
            break;
        }
    }
    cout << ans << "\n";

    return 0;
}
