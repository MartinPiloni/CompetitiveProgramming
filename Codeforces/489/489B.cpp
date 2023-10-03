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

    int n; cin >> n;
    vector<int> b(n);
    for (int i = 0; i < n; i++) cin >> b[i];
    
    int m; cin >> m;
    vector<int> g(m);
    for (int i = 0; i < m; i++) cin >> g[i];

    sort(all(b));
    sort(all(g));
    ll i = 0, j = 0, ans = 0;
    while (i != n && j != m) {
        if (abs(b[i] - g[j]) <= 1) {
            ans++;
            i++;
            j++;
        } else if (b[i] > g[j]) {
            j++;
        } else {
            i++;
        }
    }
    cout << ans << "\n";

    return 0;
}
