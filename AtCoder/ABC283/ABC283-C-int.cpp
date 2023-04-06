#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using str = string;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	ll S;
	cin >> S;

	int ans = 0;
	while (S != 0) {
		if (S % 100 == 0) {
			S /= 100;
		} else {
			// Integer division truncates decimals to 0 (~ floor in positive integers)
			S /= 10;
		}
		ans++;
	}

	cout << ans << "\n";
    return 0;
}
