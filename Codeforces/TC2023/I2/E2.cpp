#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define fst first
#define snd second
#define sz(x) ((int)x.size())
#define all(x) x.begin(),x.end()

using ll = long long;
using str = string;

const int MAXN = 1e6 + 10;
vector<int> a[10];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int x, p;
    for (int i = 1; i <= 1e6; i++)  {
        x = i;
        while (x > 9) {
            vector<int> digits;
            p = 1;
            while (x > 1) {
                if (x % 10 != 0) digits.pb(x % 10);
                x /= 10;
            }
            for (auto e : digits) p *= e;
            x = p;
        }
        a[x].pb(i);

    }

    int q;
    cin >> q;
    int l, r, k;
    for (int i = 0; i < q; i++) {
        cin >> l >> r >> k;
        cout << (upper_bound(all(a[k]), r) - a[k].begin()) - 
                (lower_bound(all(a[k]), l) - a[k].begin()) << "\n";
    }

    return 0;
}
