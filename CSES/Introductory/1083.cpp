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

    int ans = 0, x;
    for (int i = 1; i < n; i++) {
        cin >> x;
        ans ^= i;
        ans ^= x;
    }
    ans ^= n;
    cout << ans << "\n";

    return 0;
}
