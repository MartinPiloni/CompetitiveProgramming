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
        if (sz(s) == 2 && s == "()") {cout << "NO\n"; continue;}

        cout << "YES\n";
        int n = sz(s);
        bool f = false;
        for (int i = 0; i < n; i++) {if (s[i] == s[i + 1]) f = true;}
        if (f) {
            for (int i = 0; i < 2 * n; i++) {
                if (i & 1) cout << ")";
                else cout << "(";
            }
            cout << "\n";
        } else {
            for (int i = 0; i < n; i++) {
                cout << "(";
            }
            for (int i = 0; i < n; i++) {
                cout << ")";
            }
            cout << "\n";
        }
    }


    return 0;
}
