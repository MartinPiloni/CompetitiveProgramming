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

const int MAXN = 2e5 + 10;
ll dp[MAXN][4][4][4], v[MAXN], n;
str s;

ll f(int i, ll fs, ll sn, ll th) {
    if (i == n) return 0;

    ll &r = dp[i][fs][sn][th];
    if (r != -1) return r;

    r = 0;
    if (fs == 3 && s[i] == 'M') {
        r += f(i + 1, v[i], sn, th) + f(i + 1, fs, sn, th);
    } else if (fs < 3 && sn == 3 && s[i] == 'E') {
        r += f(i + 1, fs, v[i], th) + f(i + 1, fs, sn, th);
    } else if (fs < 3 && sn < 3 && th == 3 && s[i] == 'X') {
        vector<int> cnt(3, 0);
        cnt[fs]++; cnt[sn]++; cnt[v[i]]++;            
        ll mex = 3;
        fore(j, 0, 3) if (cnt[j] == 0) {mex = j; break;}

        r += mex + f(i + 1, fs, sn, th);
    } else {
        r += f(i + 1, fs, sn, th);
    }

    return r;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    mset(dp, -1);
    cin >> n;
    fore(i, 0, n) cin >> v[i];
    cin >> s;
    cout << f(0, 3, 3, 3) << "\n";

    return 0;
}
