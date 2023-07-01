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
        int  n;
        cin >> n;

        vector<int> v(n);
        fore(i, 0, n) cin >> v[i];
        sort(ALL(v));

        int ans = 0;
        for(int i = 0; i < n/2; i++) {
            ans += v[n - i - 1] - v[i];
        }

        cout << ans << "\n";
    }
    return 0;
}
