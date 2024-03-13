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
        int n, m, x;
        cin >> n >> m >> x;
        x--;

        vector<pair<int, str>> v(m);
        for (int i = 0; i < m; i++) {
            cin >> v[i].fst;
            cin >> v[i].snd;
        }

        vector<vector<bool>> vis(m + 1, vector<bool>(n));
        vis[0][x] = 1;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (vis[i][j]) {
                    int pos = j + n;
                    if (v[i].snd == "0") {
                        vis[i + 1][(pos + int(v[i].fst)) % n] = 1;
                    } else if (v[i].snd == "1") {
                        vis[i + 1][(pos - int(v[i].fst)) % n] = 1;
                    } else {
                        vis[i + 1][(pos + int(v[i].fst)) % n] = 1;
                        vis[i + 1][(pos - int(v[i].fst)) % n] = 1;
                    }
                }
            }
        }

        ll cnt = 0;
        vector<int> ans;
        for (int i = 0; i < n; i++) {
            if (vis[m][i]) {
                cnt++;
                ans.pb(i + 1);
            }
        }
        cout << cnt << "\n";
        for (auto e : ans) cout << e << " ";
        cout << "\n";
    }


    return 0;
}
