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
        ll a, b;
        cin >> a >> b;
        
        ll ans = lcm(a, b);
        if (ans == b) {
            for (int i = 2; i * i <= b; i++) {
                if (a % i == 0 || b % i == 0) {
                    ans *= i;
                    break;
                }
            }
        }
        if (ans == b) cout << ans * ans << "\n";
        else cout << ans << "\n";
    }

    return 0;
}
