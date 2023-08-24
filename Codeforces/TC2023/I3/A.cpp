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
        int x1, y1, x2, y2, x3, y3;
        cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;
        
        ll ans = abs(x2 - x1) + abs(y2 - y1);
        if ((x1 == x2 && x1 == x3 && 
            ((y1 < y3 && y3 < y2) || (y1 > y3 && y3 > y2))) || 
            (y1 == y2 && y1 == y3 && 
            ((x1 < x3 && x3 < x2) || (x1 > x3 && x3 > x2)))) ans += 2;
        
        cout << ans << "\n";
    }

    return 0;
}
