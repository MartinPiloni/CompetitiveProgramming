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
    for (int mask = 0; mask < (1 << (sz(s) - 1)); mask++) {
        ll sum = 0;
        for (int i = 0; i < sz(s); i++) {
            sum *= 10;
            sum += s[i] - '0';
            if (mask & (1 << i)) {
                ans += sum;
                sum = 0;
            }
        }
        ans += sum;
    }
    cout << ans << "\n";

    return 0;
}
