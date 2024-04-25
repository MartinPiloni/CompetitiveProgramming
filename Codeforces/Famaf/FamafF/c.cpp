#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using str = string;

#define sz(x) int((x).size())

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, q;
    cin >> n >> q; 

    vector<ll> v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }
    sort(v.begin(), v.end());
    
    vector<ll> ps(n + 1);
    ps[0] = 0;
    for (int i = 0; i < n; i++) {
        ps[i + 1] = ps[i] + v[i];
    }

    ll x, y;
    for (int i = 0; i < q; i++) {
        cin >> x >> y;
        cout << (ps[n] - ps[n - x]) - (ps[n] - ps[n - (x - y)])  << "\n";
    }

    return 0;
}
