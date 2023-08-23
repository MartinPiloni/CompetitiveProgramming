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

    int n, m, k;
    cin >> n >> m >> k;
    vector<int> v(n);

    for (int i = 0; i < n; i++) cin >> v[i];
    
    int ans = 1e9;
    for (int i = m - 1; i < n; i++) {
        if (v[i] != 0 && v[i] <= k) {
            ans = (i - (m - 1)) * 10;
            break;
        }
    }

    for (int i = m - 1; i >= 0; i--) {
        if (v[i] != 0 && v[i] <= k) {
            ans = min(ans, ((m - 1) - i) * 10);
            break;
        }
    }
    
    cout << ans << "\n";

    return 0;
}
