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
    vector<int> a(n), b(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i < n; i++) cin >> b[i];

    vector<int> diff(n);
    for (int i = 0; i < n; i++) diff[i] = a[i] - b[i];
    sort(all(diff));

    ll l = 0, r = n - 1, ans = 0;
    while (l != r) {
        if (diff[l] > -diff[r]) {
            ans += r - l;
            r--;
        } else {
            l++; 
        }
    }
    cout << ans << "\n";

    return 0;
}
