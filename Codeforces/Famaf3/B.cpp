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

const int MAXN = 1e3 + 10;
vector<ll> g[MAXN];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    
    ll p;
    fore(i, 0, n - 1) {
        cin >> p;
        p--;
        g[p].pb({i + 1});
    }

    bool ok = true;
    fore(i, 0, n) {
        ll cnt = 4;

        if (g[i].size() > 0) cnt = 0;
        for (auto w : g[i]) {
            if (g[w].size() == 0) cnt++; 
        }

        if (cnt < 3) {ok = false; break;}
    }

    (ok ? cout << "Yes\n" : cout << "No\n");
    return 0;
}
