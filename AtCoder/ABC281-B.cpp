#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using str = string;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	str s;
	cin >> s;

	if (s.size() < 8) {
		cout << "No" << "\n";
	} else {
		bool is_valid = true;
		for (int i = 2; i < (int)s.size() - 2; i++) {
			if (s[i] > '9' || s[i] < '0') {
				is_valid = false;
			}
		}

		if (s.size() == 8 && 'A' <= s[0] && s[0] <= 'Z' && 'A' <= s[s.size() - 1]
			&& s[s.size() - 1] <= 'Z' && s[1] >= '1' && is_valid) {
			cout << "Yes" << "\n";
		} else {
			cout << "No" << "\n";
		}
	}

    return 0;
}
