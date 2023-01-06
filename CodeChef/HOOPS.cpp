#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using str = string;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int  t;
	cin >> t;

	int n, ans;
	while(t--) {
	    cin >> n;
	    ans = n / 2 + 1;
	    cout << ans << "\n";
	}

    return 0;
}
