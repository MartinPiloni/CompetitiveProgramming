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
        ll sum = 0;
        bool f = false;
        for (int i = 0; i < n; i++) {
            cin >> v[i];
            sum += v[i];

            if (v[i] % 3 == 1) f = true;
        }

        if (sum % 3 == 0) cout << "0\n";
        else if (sum % 3 == 2) cout << "1\n";
        else if (sum % 3 == 1 && f) cout << "1\n";
        else cout << "2\n";
    }

    return 0;
}
