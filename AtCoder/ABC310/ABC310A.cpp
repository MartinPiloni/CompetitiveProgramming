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

    int n, p, q;
    cin >> n >> p >> q;

    int ans = p;
    vector<int> v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
        ans = min(ans, q + v[i]);
    }

    cout << ans << "\n";
    return 0;
}
