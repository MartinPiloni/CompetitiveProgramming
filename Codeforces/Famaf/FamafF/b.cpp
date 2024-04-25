#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using str = string;

#define sz(x) int((x).size())

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    
    vector<ll> v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }

    int cnt = 0, ans = 0;
    for (int i = 0; i < n; i++) {
        if (i == 0 || v[i] > v[i - 1]) cnt++;
        else {
            ans = max(ans, cnt);
            cnt = 1;
        }
    }

    ans = max(ans, cnt);
    cout << ans << "\n";
    return 0;
}
