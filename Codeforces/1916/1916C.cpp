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
        vector<ll> v(n), ps(n + 1), odds(n + 1), even(n + 1);
        for (int i = 0; i < n; i++) {
            cin >> v[i];
            ps[i + 1] = ps[i] + v[i];
            odds[i + 1] = odds[i] + (v[i] & 1);
            even[i + 1] = even[i] + (v[i] % 2 == 0);
        }
        cout << v[0] << " \n"[n == 1];
        for (int i = 2; i < n + 1; i++) {
            cout << ps[i] - (odds[i] / 3) - (odds[i] % 3 == 1) << " \n"[i == n];
        }
    }

    return 0;
}
