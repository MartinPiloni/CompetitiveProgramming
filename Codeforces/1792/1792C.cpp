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
        vector<int> pos(n);
        int x;
        for (int i = 0; i < n; i++) {
            cin >> x;
            x--;
            pos[x] = i;
        }

        int first = 0, last = n - 1, l = 0, r = 0, l2 = 1e9, r2 = 1e9;
        auto pos2 = pos;
        for (int i = (n / 2) - 1; i > 0; i--) {
            if (pos2[i] < pos2[i - 1]) {
                first--;
                l++;
                pos2[i - 1] = first;
            }
        }
        for (int i = (n / 2); i < n; i++) {
            if (pos2[i] < pos2[i - 1]) {
                last++;
                r++;
                pos2[i] = last;
            }
        }

        if (n & 1) {
            first = 0, last = n - 1; 
            l2 = 0, r2 = 0;
            for (int i = (n / 2); i > 0; i--) {
                if (pos[i] < pos[i - 1]) {
                    first--;
                    l2++;
                    pos[i - 1] = first;
                }
            }
            for (int i = (n / 2) + 1; i < n; i++) {
                if (pos[i] < pos[i - 1]) {
                    last++;
                    r2++;
                    pos[i] = last;
                }
            }
        }

        if (n % 2 == 0) cout << max(l, r) << "\n";
        else cout << min(max(l, r), max(l2, r2)) << "\n";
    }
    return 0;
}
