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

    int n, m;
    cin >> n >> m;
    str g[n];
    for (int i = 0; i < n; i++) cin >> g[i];

    vector<bool> seen('z' - 'a');
    ll ans = 0;
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < m - 1; j++) {
            seen[g[i][j] - 'a'] = true; 
            seen[g[i + 1][j] - 'a'] = true; 
            seen[g[i][j + 1] - 'a'] = true; 
            seen[g[i + 1][j + 1] - 'a'] = true; 
            if (seen['f' - 'a'] && seen['a' - 'a'] && seen['c' - 'a'] && seen['e' - 'a']) ans++;
            seen['f' - 'a'] = 0;
            seen['a' - 'a'] = 0;
            seen['c' - 'a'] = 0; 
            seen['e' - 'a'] = 0;
        }
    }

    cout << ans << "\n";
    return 0;
}
