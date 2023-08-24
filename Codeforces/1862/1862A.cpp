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
        int n, m;
        cin >> n >> m;
        vector<char> v[m];
        
        char x;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> x;
                v[j].pb(x);
            }
        }

        str s = "vika";
        int cnt = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) if (v[i][j] == s[cnt]) {cnt++; break;}
            if (cnt == 4) break;
        }

        (cnt == 4 ? cout << "YES\n" : cout << "NO\n");
    }

    return 0;
}
