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
        ll n, k;
        str s;
        cin >> n >> k >> s;

        ll ans = 0;
        for (int i = 0; i < n; i++) {
            if (s[i] == 'B') {
                ans++;
                for (int j = 0; j < k; j++) {
                    if (i + j == n) break;
                    s[i + j] = 'W'; 
                }
            }
        }
        cout << ans << "\n";
    }

    return 0;
}
