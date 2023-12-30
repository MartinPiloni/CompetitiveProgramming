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
        int n;
        str s;
        cin >> n >> s;

        char last = '1', c;
        for (int i = 0; i < n; i++) {
            if (s[i] != '0' && s[i] != '1') {
                if (i != 0 && (s[i - 1] == '0' || s[i - 1] == '1')) {
                    last = s[i - 1];
                }

                c = s[i];
                if (last == '1') s[i] = '0';
                else s[i] = '1';

                last = s[i];
                for (int j = i + 1; j < n; j++) {
                    if (s[j] == c) s[j] = last;
                }
            }
        }

        bool ok = true;
        for (int i = 1; i < n; i++) {
            if (s[i] == s[i - 1])  {
                ok = false;
                break;
            }
        }
        (ok ? cout << "YES\n" : cout << "NO\n");
    }

    return 0;
}
