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
        int n; str s;
        cin >> n >> s;
        
        ll ans = 0;
        vector<bool> r(1e6 + 10);
        for (int i = 1; i <= n; i++) {
            if (s[i - 1] == '1') continue;
            for (int j = i; j <= n; j += i) {
                if (s[j - 1] == '1') break;

                if (!r[j] && s[j - 1] == '0') {
                    ans += i;
                    r[j] = true;
                }
            }
        }
        cout << ans << "\n";
    }

    return 0;
}
