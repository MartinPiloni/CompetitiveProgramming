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

    int n, m;
    cin >> n >> m;
    
    vector<str> order(n);
    fore(i, 0, n) cin >> order[i];

    vector<str> d(m);
    fore(i, 0, m) cin >> d[i];

    int a;
    cin >> a;
    vector<int> p(m);
    fore(i, 0, m) cin >> p[i];

    map<str, int> price;
    fore(i, 0, m) price[d[i]] = p[i];

    int ans = 0;
    fore(i, 0, n) {
        if(price[order[i]] == 0) ans += a;
        else ans += price[order[i]];
    }

    cout << ans << "\n";

    return 0;
}
