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
        int n;
        cin >> n;
        
        ll w, r, x, y;
        bool ok = true;
        cin >> w >> r;
        for (int i = 0; i < n - 1; i++) {
            cin >> x >> y;
            if (x >= w && y >= r) ok = false; 
        }
        (ok ? cout << w << "\n" : cout << "-1\n");
    }

    return 0;
}
