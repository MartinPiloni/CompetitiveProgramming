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

#define sz(x) int((x).size())

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;

        vector<ll> v(n);
        fore(i, 0, n) cin >> v[i];

        ll s = 0, ops = 0;
        bool f = false;
        fore(i, 0, n) {
            if (v[i] < 0 && !f) {
                ops++;
                f = true;
            } else if (v[i] > 0) f = false;
            s += abs(v[i]);
        }

        cout << s << " " << ops << "\n";
    }

    return 0;
}
