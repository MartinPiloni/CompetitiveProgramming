#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define fst first
#define snd second
#define sz(x) ((int)x.size())
#define all(x) x.begin(),x.end()

using ll = long long;
using str = string;

bool is_good(str s) {
    for (int i = 1; i < sz(s); i++) {
        if (s[i] == s[i - 1]) return false;
    }
    return true;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int tt;
    cin >> tt;
    while (tt--) {
        int n, m;
        str s, t;
        cin >> n >> m >> s >> t;

        bool f1 = is_good(s);
        bool f2 = is_good(t);

        if (f1) cout << "YES\n";
        else if (!f1 && !f2) cout << "NO\n";
        else {
            bool ok = true;
            for (int i = 1; i < sz(s); i++) {
                if (s[i] == s[i - 1] && (s[i - 1] == t[0] || s[i] == t[sz(t) - 1])) ok = false;
            }

            (ok ? cout << "YES\n" : cout << "NO\n");
        }

    }

    return 0;
}
