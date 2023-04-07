#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using str = string;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
    
    int n;
    cin >> n;

    vector<ll> partial_sum(n + 1, 0);
    for (int i = 0; i < n; i++) {
        cin >> partial_sum[i + 1];
        partial_sum[i + 1] += partial_sum[i];
    }

    ll min_prefix = 0, ans = -9e18;
    for (int i = 0; i < n; i++) {
        ans = max(partial_sum[i + 1] - min_prefix, ans);
        min_prefix = min(min_prefix, partial_sum[i + 1]);
    }

    cout << ans << "\n";
    return 0;
}
