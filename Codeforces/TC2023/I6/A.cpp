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
    vector<int> cnt(110);
    for (int i = 0; i < n; i++) {
        cin >> x;
        cnt[x]++;
        ans = max(ans, cnt[x]);
    }
    cout << ans << "\n";

    return 0;
}
