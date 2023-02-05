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

		int a = 0, b = 0, c = 3, deal = 1, cards_left = n;
		for (int i = 0; i < n; i++) {
			if (c == 0 || c == 1) {
				if (cards_left - deal < 0) {
					b += cards_left;
					break;
				} else {
					b += deal;
				}
				cards_left -= deal;
				deal++;
				c++;
			} else {
				if (cards_left - deal < 0) {
					a += cards_left;
					break;
				} else {
					a += deal;
				}
				cards_left -= deal;
				deal++;
				c++;
				if (c == 4) {
					c = 0;
				}
			}
		}
		cout << a << " " << b << "\n";
	}

    return 0;
}
