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
        str s;
        cin >> s;

        bool f = true;
        ll cnt = 0, max_cnt = 0;
        fore(i, 0, SZ(s)) {
            if (s[i] == '1') cnt++;
            else {
                f = false;
                max_cnt = max(max_cnt, cnt);
                cnt = 0;
            }
        }
        if(!f && cnt > 0) {
            fore(i, 0, SZ(s)) {
                if (s[i] == '1') cnt++;
                else break;
            }
        }
        max_cnt = max(max_cnt, cnt);

        ll ans = 0;
        if (max_cnt == 1) ans = 1;
        else if (!f) {
            fore(i, 0, max_cnt) {
                ans = max(ans, (max_cnt - i) * (i + 1));
            }
        } else {
            ans = max_cnt * SZ(s);
        }

        cout << ans << "\n";
    }
    return 0;
}

/*
011111
101111
110111
111011
111101
111110

cnt = 5
5 * 1
4 * 2
3 * 3
2 * 4
1 * 5

(cnt - i) * (n - (n - i + 1))
cnt * (n - (n - 1))
(cnt - 1) * (n - (n - 2))

*/