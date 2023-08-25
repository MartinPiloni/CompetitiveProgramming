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

    int q;
    cin >> q;

    vector<str> v, r;
    str s;
    bool f = true;
    for (int i = 0; i < q; i++) {
        int t;
        cin >> t;

        if (t == 1) {
            cin >> s;
            if (f) {
                v.pb(s);
                reverse(s.begin(), s.end());
                r.pb(s);
            } else {
                r.pb(s);
                reverse(s.begin(), s.end());
                v.pb(s);
            }
        } else if (t == 2) {
            cin >> s;
            if (f) {
                bool ans = false;
                for (auto e : v) {
                    if (sz(e) < sz(s)) continue;

                    bool c = true;
                    for (int j = 0; j < sz(s); j++) c &= (s[j] == e[j]);
                    if (c) {ans = true; break;}
                }
                (ans ? cout << "1\n" : cout << "0\n");
            } else {
                bool ans = false;
                for (auto e : r) {
                    if (sz(e) < sz(s)) continue;

                    bool c = true;
                    for (int j = 0; j < sz(s); j++) c &= (s[j] == e[j]);
                    if (c) {ans = true; break;}
                }
                (ans ? cout << "1\n" : cout << "0\n");

            }
        } else if (t == 3) {
            f = !f;
        }
    }

    return 0;
}
