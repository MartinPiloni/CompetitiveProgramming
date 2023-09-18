#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define fst first
#define snd second
#define sz(x) ((int)x.size())
#define all(x) x.begin(),x.end()

using ll = long long;
using str = string;

const int MAXN = 1e2 + 10;
ll g[MAXN][MAXN];
bool erase[MAXN][MAXN];
int n;

bool floyd() {
    bool can = true;
    for (int k = 0; k < n; ++k) {
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; j++) {
                if (g[i][j] > g[i][k] + g[k][j]) return false;
                else if (i != k && k != j && g[i][j] == g[i][k] + g[k][j]) {
                    erase[i][j] = true;
                    erase[j][i] = true;
                }
                g[i][j] = min(g[i][j], g[i][k] + g[k][j]);
            }
        }
    }
    return can;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> g[i][j];
        }
    }

    bool can = floyd();
    if (!can) cout << "-1\n";
    else {
        ll ans = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (erase[i][j]) {
                    ans++;
                    erase[i][j] = false;
                    erase[j][i] = false;
                }
            }
        }
        cout << ans << "\n";
    }

    return 0;
}
