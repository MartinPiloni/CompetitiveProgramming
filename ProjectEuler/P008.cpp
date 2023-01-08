#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using db = double;
using str = string;

#define sz(x) (int) (x).size()

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	str number;
	cin >> number;

	ll ans = 0;
	ll mult;
	for (int i = 0; i < sz(number) - 14; i++) {
		mult = 1;
		for (int j = i; j < i + 13; j++) {
			mult = mult * (number[j] - '0');
		}
		ans = max(mult, ans);
	}

	cout << ans << "\n";
    return 0;
}
