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
        str s;
        cin >> s;

        bool ok = false;
        if (s[0] == 'B' || s[sz(s) - 1] == 'B') ok = true;

        ll tot_a = 0, cnt = 0, min_s = 1e9;
        for (int i = 0; i < sz(s); i++) {
            if (s[i] == 'A') {
                tot_a++;
                cnt++;
            } else if (i < sz(s) && s[i] == 'B' && s[i + 1] == 'B') {
                ok = true;
                min_s = min(min_s, cnt);
                cnt= 0;
            } else {
                min_s = min(min_s, cnt);
                cnt = 0;
            }
        }
        min_s = min(min_s, cnt);
        (ok ? cout << tot_a << "\n" : cout << tot_a - min_s << "\n");
    }

    return 0;
}
