#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(int i=a,ggdem=b;i<ggdem;++i)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))

using ll = long long;
using str = string;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        ll n, x1, y1, x2, y2;
        cin >> n >> x1 >> y1 >> x2 >> y2;
        ll l_1 = min({x1, n - x1 + 1, y1, n - y1 + 1});
        ll l_2 = min({x2, n - x2 + 1, y2, n - y2 + 1});
        cout << abs(l_2 - l_1) << "\n";
    }

    return 0;
}