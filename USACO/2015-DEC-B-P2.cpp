#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using str = string;

#define sz(x) (int) (x).size()

void setIO(string name = "") {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
	if ((int) name.size()) {
		freopen((name + ".in").c_str(), "r", stdin);
		freopen((name + ".out").c_str(), "w", stdout);
	}
}

int main() {
	setIO("speeding");

	int n, m;
	cin >> n >> m;

	vector<pair<int, int>> segments(n);

	int length, speed_limit;
	for (int i = 0; i < n; i++) {
		cin >> length >> speed_limit;
		segments[i] = make_pair(length, speed_limit);
	}

	int speed, ans = 0, i = 0, travelled = 0, segment_length = segments[i].first;
	for (int j = 0; j < m; j++) {
		cin >> length >> speed;
		travelled += length;
		ans = max(ans, speed - segments[i].second);
		while (travelled >= segment_length) {
			i++;
			if (travelled > segment_length) {
				ans = max(ans, speed - segments[i].second);
			}
			segment_length += segments[i].first;
		}
	}

	cout << ans << "\n";
    return 0;
}
