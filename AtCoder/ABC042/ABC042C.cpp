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

    int n, k;
    cin >> n >> k;
    set<int> digits;
    int d;
    for (int i = 0; i < k; i++) {
        cin >> d;
        digits.insert(d);
    }

    ll ans = 0;
    for (int i = n; i < 100000; i++) {
        int x = i;
        bool ok = true;    
        while (x != 0) {
            d = x % 10;
            x /= 10;
            if (digits.count(d) > 0) {
                ok = false;
                break;
            }
        }
        if (ok) {
            ans = i;
            break;
        }
    }
    cout << ans << "\n";

    return 0;
}
