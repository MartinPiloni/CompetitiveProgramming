#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define fst first
#define snd second
#define sz(x) ((int)x.size())
#define all(x) x.begin(),x.end()

using ll = long long;
using str = string;
using ld = long double;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, l;
    cin >> n >> l;
    vector<int> v(n);
    for (int i = 0; i < n; i++) cin >> v[i];
    sort(all(v));

    int ans = 0;
    for (int i = 0; i < n - 1; i++) ans = max(ans, v[i + 1] - v[i]);

    if (v[0] != 0 && v[0] >= l - v[n - 1] && (ld)v[0] > (ld)(ans / 2)) cout << v[0] << "\n";
    else if (v[n - 1] != l && l - v[n - 1] > v[0] && (ld)l - v[n - 1] > (ld)(ans / 2)) cout << l - v[n - 1] << "\n";
    else cout << fixed << setprecision(20) << (ld)ans / 2 << "\n";

    return 0;
}
