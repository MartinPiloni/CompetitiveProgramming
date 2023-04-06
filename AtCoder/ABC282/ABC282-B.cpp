#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using str = string;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int participants, problems;
	cin >> participants >> problems;

	str solutions[participants];
	for (int i = 0; i < participants; i++) {
		cin >> solutions[i];
	}

	int ans = 0;
	bool can_solve;
	for (int i = 0; i < participants - 1; i++) {
		for (int j = i + 1; j < participants; j++) {
			can_solve = true;
			for (int k = 0; k < problems; k++) {
				if (solutions[i][k] != 'o' && solutions[j][k] != 'o') {
					can_solve = false;
					break;
				}
			}
			if (can_solve) {
				ans += 1;
			}
		}
	}

	cout << ans << "\n";
    return 0;
}
