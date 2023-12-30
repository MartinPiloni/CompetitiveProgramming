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
        vector<ll> v(n);
        vector<ll> ps(n);
        for (int i = 0; i < n; i++) {
            cin >> v[i];
            if (i & 1) v[i] *= -1;

            if (i > 0) ps[i] = ps[i - 1] + v[i];
            else ps[i] = v[i];
        }

        //for (auto e : v) cout << e << " ";
        //cout << endl;

        set<ll> s;
        bool ok = false;
        for (int i = 0; i < n; i++) {
            if (ps[i] == 0 || s.count(ps[i]) > 0) {
                ok = true;
                break;
            }
            s.insert(ps[i]);
        }
        (ok ? cout << "YES\n" : cout << "NO\n");
    }

    return 0;
}
