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

        ll ans = 0;
        for (int i = 0; i < n - 2; i++) {
            if (s[i] == 'm' && s[i + 1] == 'a' && s[i + 2] == 'p') {
                ans++;
                if (i + 3 < n && s[i + 3] == 'i') i = i + 2;
            }
            else if (s[i] == 'p' && s[i + 1] == 'i' && s[i + 2] == 'e') ans++;
        }
        cout << ans << "\n";
    }

    return 0;
}
