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
	setIO("shell");

	int swaps;
	cin >> swaps;

	vector<vector<int>> pebble(3, vector<int> (swaps + 1));
	vector<int> score(3);

	// Pebble possible start
	for (int i = 0; i < 3; i++) {
		pebble[i][0] = i + 1;
	}

	for (int swap = 0; swap < swaps; swap++) {
		int a, b, g;
		cin >> a >> b >> g;

		for (int i = 0; i < 3; i++) {
			int p_pos = pebble[i][swap];
			if (p_pos == a) {
				p_pos = b;
			} else if (p_pos == b) {
				p_pos = a;
			}
			pebble[i][swap + 1] = p_pos;

			if (g == p_pos) {
				score[i]++;
			}
		}
	}

	cout << max(score[0], max(score[1], score[2])) << "\n";
    return 0;
}
