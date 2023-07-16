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
    
    vector<int> price(n);
    vector<vector<bool>> v(n, vector<bool>(m));
    int q, function;
    for (int i = 0; i < n; i++) {
        cin >> price[i];
        cin >> q;
        for (int j = 0; j < q; j++) {
            cin >> function;
            function--;
            v[i][function] = true;
        }
    }

    bool ok = false;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (price[i] < price[j] || i == j) continue;

            bool ok2 = true;
            bool l = false;
            for (int k = 0; k < m; k++) {
                if (v[i][k] == 1 && v[j][k] == 0) {ok2 = false; break;}
                else if (v[i][k] == 0 && v[j][k] == 1) l = true;
            }

            if (!ok2 || (price[i] == price[j] && !l)) continue;
            else {ok = true; break;}
        }
        if (ok) break;
    }

    (ok ? cout << "Yes\n" : cout << "No\n");

    return 0;
}
