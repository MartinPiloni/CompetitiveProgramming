#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using str = string;

void setIO(string name = "") {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
	if ((int) name.size()) {
		freopen((name + ".in").c_str(), "r", stdin);
		freopen((name + ".out").c_str(), "w", stdout);
	}
}

int main() {
	setIO("buckets");

	str row;
	int barn_x, barn_y;
	int rock_x, rock_y;
	int lake_x, lake_y;
	for (int i = 0; i < 10; i++) {
		cin >> row;
		for (int j = 0; j < 10; j++) {
			if (row[j] == 'B') {
				barn_x = j;
				barn_y = i;
			} else if (row[j] == 'R') {
				rock_x = j;
				rock_y = i;
			} else if (row[j] == 'L') {
				lake_x = j;
				lake_y = i;
			}
		}
	}

	int cows = abs(barn_x - lake_x) + abs(barn_y - lake_y) - 1;

	if (barn_x == lake_x && barn_x == rock_x &&
		(barn_y < rock_y && rock_y < lake_y
		|| (lake_y < rock_y && rock_y < barn_y))) {
		cows += 2;
	}

	else if (barn_y == lake_y && barn_y == rock_y &&
	   ((barn_x < rock_x && rock_x < lake_x)
	   || (lake_x < rock_x && rock_x < barn_x))) {
		cows += 2;
	}

	cout << cows << "\n";
    return 0;
}
