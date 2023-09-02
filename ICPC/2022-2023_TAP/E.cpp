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
    vector<int> v(n), a(1e6 + 10);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }

    int ans = 0;
    for (auto e : v) {
        if (a[e] == 0) {
            ans++;
            a[e - 1]++;
        } else {
            a[e]--;
            a[e - 1]++;
        }
    }

    cout << ans << "\n";
    return 0;
}
