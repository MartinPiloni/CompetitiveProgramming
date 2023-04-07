#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using str = string;

#define sz(x) (int) (x).size()

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

    int n;
    cin >> n;

    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    sort(a.begin(), a.end());

    ll ans = 0, c = 0, x = a[0];
    for (int i = 0; i < n; i++) {
        if (x == a[i]) {
            c++;
        } else {
            ans += c * (n - i);
            c = 1;
            x = a[i];
        }
    }

    cout << ans << "\n";
    return 0;
}

