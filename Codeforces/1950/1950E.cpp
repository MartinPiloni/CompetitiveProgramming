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

        int ans = n;
        for (int i = 1; i <= n; i++) {
            if (n % i > 0) continue;

            for (int j = 0; j < 2; j++) {
                int errors = 0;

                for (int k = 0; k < n; k++) {
                    if (s[k] != s[k % i]) errors++;
                }

                if (errors < 2) {
                    ans = i;
                    break;
                }

                reverse(all(s));
            }

            if (ans < n) break;
        }
        cout << ans << "\n";


    }

    return 0;
}
