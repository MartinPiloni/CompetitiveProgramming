#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(int i=a;i<b;++i)
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
    while(t--) {
        ll n, m, x;
        cin >> n >> m;

        vector<vector<ll>> c(m);
        fore(i, 0, n) {
            fore(j, 0, m) {
                cin >> x;
                c[j].push_back(x);
            }
        }
        fore(i, 0, m) sort(ALL(c[i]));

        vector<vector<ll>> p_s(m);
        fore(i, 0, m) p_s[i].pb(0);
        fore(i, 0, m) {
            fore(j, 0, SZ(c[i])) {
                p_s[i].pb(p_s[i][j] + c[i][j]);
            }
        }

        ll ans = 0;
        fore(i, 0, m) {
            fore(j, 0, SZ(c[i])) {
                ans += c[i][j] * (ll)j - p_s[i][j];
            }
        }

        cout << ans << "\n";
    }

    return 0;
}

/*
1 --> 1 * 0 - 0 = 0
3 --> 3 * 1 - 1 = 2
7 --> 7 * 2 - 4 = 10
ans             = 12
*/