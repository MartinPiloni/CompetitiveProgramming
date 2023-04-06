#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using str = string;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	str S;
	cin >> S;

	int ans = 0;
	while (!S.empty()) {
		char last_char = S.back();
		S.pop_back();
		if (last_char == '0' && S.back() == '0') {
			// If number is divisible by 100 drop one more char
			S.pop_back();
		}
		ans++;
	}

	cout << ans << "\n";
    return 0;
}
