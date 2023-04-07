#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using str = string;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

    int n;
    cin >> n;
    
    vector<ll> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    vector<ll> prefix_sum(n + 1);
    prefix_sum[0] = 0;
    for (int i = 0; i < n; i++) {
        prefix_sum[i + 1] = prefix_sum[i] + a[i];
    }

    ll min_prefix = prefix_sum[0];
    ll ans = -9e18;
    for (int i = 0; i <  n; i++) {
        ans = max(ans, prefix_sum[i + 1] - min_prefix);
        min_prefix = min(min_prefix, prefix_sum[i + 1]);
    }

    cout << ans << "\n";
    return 0;
}

