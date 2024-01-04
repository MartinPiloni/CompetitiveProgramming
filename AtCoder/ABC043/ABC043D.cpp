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
    str s;
    cin >> s;
    bool ok = false;
    for (int i = 1; i < sz(s); i++) {
        if (s[i] == s[i - 1]) {
            ok = true;
            cout << i << " " << i + 1 << "\n";
            break;
        } else if (i > 1 && s[i] == s[i - 2]) {
            ok = true;
            cout << i - 1 << " " << i + 1 << "\n";
            break;
        }
    }
    if (!ok) cout << "-1 -1\n";

    return 0;
}
