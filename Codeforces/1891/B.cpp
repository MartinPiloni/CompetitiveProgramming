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
        int n, q;
        cin >> n >> q;
        vector<ll> v(n), x;
        for (int i = 0; i < n; i++) cin >> v[i];
        
        int in;
        for (int i = 0; i < q; i++) {
            cin >> in;
            if (x.empty()) x.pb(in);
            else if (x.back() > in) x.pb(in);
        }

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < sz(x); j++) {
                if (v[i] % (1 << x[j]) == 0) {
                    v[i] += 1 << (x[j] - 1);
                }
            }
            cout << v[i] << " ";
        }
        cout << "\n";
    }

    return 0;
}
