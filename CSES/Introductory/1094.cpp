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

    int n;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++) cin >> v[i];

    ll ans = 0;
    for (int i = 1; i < n; i++) {
        if (v[i - 1] > v[i]) {
            ans += v[i - 1] - v[i];
            v[i] = v[i - 1];
        }
    }
    cout << ans << "\n";

    return 0;
}
