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
        int n, m, k;
        cin >> n >> m >> k;

        int v_x, v_y;
        cin >> v_x >> v_y;

        bool ans = true; 
        int x, y;
        for (int i = 0; i < k; i++) {
            cin >> x >> y;
            if (((abs(v_x - x) + abs(v_y - y)) % 2) == 0) ans = false;
        }

        (ans ? cout << "YES\n" : cout << "NO\n");
    }
    return 0;
}
