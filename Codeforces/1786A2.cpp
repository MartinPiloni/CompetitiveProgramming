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

		int c = 0, deal = 2, cards_left = n - 1;
		pair<int, int> a = {1, 0}, b = {0 , 0};
		bool even = false;

		for (int i = 1; i < n; i++) {
			if (c == 0 || c == 1) {
				if (cards_left - deal < 0) {
					if (cards_left % 2 == 0) {
						b.first += cards_left / 2;
						b.second += cards_left / 2;
					} else if (even) {
						b.first += cards_left / 2 + 1;
						b.second += cards_left / 2;
					} else {
						b.first += cards_left / 2;
						b.second += cards_left / 2 + 1;
					}
					break;
				} else {
					if (deal % 2 == 0) {
						b.first += deal / 2;
						b.second += deal / 2;
					} else if (even) {
						b.first += deal / 2 + 1;
						b.second += deal / 2;
						even = !even;
					} else {
						b.first += deal / 2;
						b.second += deal / 2 + 1;
						even = !even;
					}
				}
				cards_left -= deal;
				deal++;
				c++;
			} else {
				if (cards_left - deal < 0) {
					if (cards_left % 2 == 0) {
						a.first += cards_left / 2;
						a.second += cards_left / 2;
					} else if (even) {
						a.first += cards_left / 2 + 1;
						a.second += cards_left / 2;
					} else {
						a.first += cards_left / 2;
						a.second += cards_left / 2 + 1;
					}
					break;
				} else {
					if (deal % 2 == 0) {
						a.first += deal / 2;
						a.second += deal / 2;
					} else if (even) {
						a.first += deal / 2 + 1;
						a.second += deal / 2;
						even = !even;
					} else {
						a.first += deal / 2;
						a.second += deal / 2 + 1;
						even = !even;
					}
				}
				cards_left -= deal;
				deal++;
				c++;
				if (c == 4) {
					c = 0;
				}
			}
		}
		cout << a.first << " " << a.second << " " << b.first << " " << b.second << "\n";
	}

    return 0;
}
