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
    
    ll ans = 0;
    for (int i = 0; i < sz(s); i++) {
        if (s[i] == 'Q') {
            for (int j = i + 1; j < sz(s); j++) {
                if (s[j] == 'A') {
                    for (int k = j + 1; k < sz(s); k++) {
                        if (s[k] == 'Q') ans++;
                    }
                }
            }
        }
    }
    cout << ans << "\n";

    return 0;
}
