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
		int ax, ay, bx, by;
		cin >> ax >> ay >> bx >> by;

		str ans;
		if (sqrt(pow(ax, 2) + pow(ay, 2)) > sqrt(pow(bx, 2) + pow(by, 2))) {
			ans = "ALEX\n";
		} else if (sqrt(pow(ax, 2) + pow(ay, 2)) == sqrt(pow(bx, 2) + pow(by, 2))) {
			ans = "EQUAL\n";
		} else {
			ans = "BOB\n";
		}
		cout << ans;
	}

    return 0;
}