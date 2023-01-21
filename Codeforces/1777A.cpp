#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using str = string;

#define sz(x) (int) (x).size()

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

    int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;

        int num, p = -1, ans = 0;
        for (int i = 0; i < n; i++) {
            cin >> num;
            if (i != 0 && p == num % 2) ans++;
            p = num % 2;
        }

        cout << ans << "\n";
    }
    return 0;
}
