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

    int n, x, y;
    cin >> n;
    vector<pair<int, int>> v(n);
    for (int i = 0; i < n; i++) {
        cin >> x >> y;
        v[i] = {-y, -x};
    }
    sort(all(v));

    int cnt = 1, j = 0, ans = 0;
    while (cnt != 0 && j < n) {
        cnt += v[j].fst * -1;
        ans += v[j].snd * -1;
        j++;
        cnt--;
    }
    cout << ans << "\n";

    return 0;
}
