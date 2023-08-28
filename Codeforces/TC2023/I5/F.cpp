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

    int n, x, ans = 0;
    cin >> n;
    vector<int> seen(5e3 + 10);
    for (int i = 0; i < n; i++) {cin >> x; seen[x] = true;}
    for (int i = 1; i <= n; i++) {if (!seen[i]) ans++;}
    cout << ans << "\n";

    return 0;
}
