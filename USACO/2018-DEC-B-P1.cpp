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
	setIO("mixmilk");

	vector<ll> capacity(3);
	vector<ll> milk(3);
	for (int i = 0; i < 3; i++) {
		cin >> capacity[i];
		cin >> milk[i];
	}

	for (int i = 0; i < 100; i++) {
		ll capacity_left = capacity[(i + 1) % 3] - milk[(i + 1) % 3];
		if (milk[i % 3] <= capacity_left) {
			milk[(i + 1) % 3] += milk[i % 3];
			milk[i % 3] = 0;
		} else {
			milk[(i + 1) % 3] = capacity[(i + 1) % 3];
			milk[i % 3] -= capacity_left;
		}
	}

	cout << milk[0] << "\n" << milk[1] << "\n" << milk[2] << "\n";
    return 0;
}
