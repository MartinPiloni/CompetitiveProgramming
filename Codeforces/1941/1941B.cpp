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
        for (int i = 0; i < n; i++) cin >> v[i];

        bool can = true;
        int l = 0;
        while (l < n - 2) {
            if (v[l] == 0) {
                l++;
                continue;
            }

            v[l + 1] -= 2 * v[l];
            v[l + 2] -= v[l];
            v[l] = 0;
            
            if (v[l + 1] < 0 || v[l + 2] < 0) {
                can = false;
                break;
            }
            l++;
        }
        can &= v[n - 1] == 0 && v[n - 2] == 0;
        (can ? cout << "YES\n" : cout << "NO\n");
    }

    return 0;
}
