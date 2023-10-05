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
    vector<int> v(n);
    for (int i = 0; i < n; i++) cin >> v[i];
    map<int, int> m;

    int ans = 0, maxv = 0;
    for (int i = 0; i < n; i++) {
        m[v[i]] = m[v[i] - 1] + 1;
        if (m[v[i]] > ans) {
            ans = m[v[i]];
            maxv = v[i];
        }
    }

    cout << ans << "\n";
    
    int e = maxv + 1 - ans;
    for (int i = 0; i < n; i++) {
        if (v[i] == e) {
            cout << i + 1 << " \n"[e == maxv];
            e++;
        } 

        if (e > maxv) break;
    }

    return 0;
}
