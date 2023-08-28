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

    int n, t;
    cin >> n >> t;
    vector<ll> v(n);
    for (int i = 0; i < n; i++) cin >> v[i];

    int l = 0, r = 0;
    ll sum = 0, ans = 0, cnt = 0;
    while (l < n) {
        if (r < n && sum + v[r] <= t) {
            sum += v[r]; 
            r++; 
            cnt++;
        } else if (sum + v[r] > t) {
            ans = max(ans, cnt); 
            cnt--;
            sum -= v[l]; 
            l++;
        } else break;
    }

    ans = max(ans, cnt);
    cout << ans << "\n";

    return 0;
}
