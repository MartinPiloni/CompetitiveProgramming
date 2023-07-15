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
        vector<int> v(n);
        for (int i = 0; i < n; i++) cin >> v[i];

        if (n < 4) {
            cout << "-1\n"; 
            continue;
        }

        int l = 0, r = n - 1, n_min = 1, n_max = n;
        while (r - l >= 3) {
            if (v[l] == n_min) {l++; n_min++;}
            else if (v[l] == n_max) {l++; n_max--;}
            else if (v[r] == n_min) {r--; n_min++;}
            else if (v[r] == n_max) {r--; n_max--;}
            else break;
        }

        if (r - l < 3) cout << "-1\n";
        else cout << l + 1 << " " << r + 1 << "\n";
    }

    return 0;
}
