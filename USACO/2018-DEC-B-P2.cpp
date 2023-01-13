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
	setIO("blist");

	int N;
	cin >> N;

	vector<pair<int, int>> milk_time(N);
	vector<int> buckets_needed(N);

	int start, end, total_time = 0;
	for (int i = 0; i < N; i++) {
		cin >> start >> end;
		milk_time[i] = make_pair(start, end);
		total_time = max(total_time, end);
		cin >> buckets_needed[i];
	}

	int ans = 0;
	for (int i = 0; i < total_time; i++) {
		int current_buckets = 0;
		for (int j = 0; j < N; j++) {
			if (milk_time[j].first <= i && i <= milk_time[j].second) {
				current_buckets += buckets_needed[j];
			}
		}
		ans = max(ans, current_buckets);
	}

	cout << ans << "\n";
    return 0;
}
