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
	setIO("shuffle");

	int N;
	cin >> N;

	vector<int> cows(N);
	vector<int> shuffle(N);

	for (int i = 0; i < N; i++) {
		cin >> shuffle[i];
	}

	for (int i = 0; i < N; i++) {
		cin >> cows[i];
	}

	for (int i = 0; i < 3; i++) {
		vector<int> past_order(N);
		for (int j = 0; j < N; j++) {
			past_order[j] = cows[shuffle[j] - 1];
		}
		cows = past_order;
	}


	for (int i = 0; i < N; i++) {
		cout << cows[i] << "\n";
	}
    return 0;
}
