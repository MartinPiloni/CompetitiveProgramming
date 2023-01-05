#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using str = string;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	str s;
	cin >> n >> s;

	bool can_swap = true;
	for (int i = 0; i < n; i++) {
		if (s[i] == '"') {
			can_swap = !can_swap;
		} else if (s[i] == ',' && can_swap) {
			s[i] = '.';
		}
	}

	cout << s << "\n";
    return 0;
}
