#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using db = double;
using str = string;

#define sz(x) (int) (x).size()

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n;
	cin >> n;
	vector<int> trees(n);

	for (int i = 0; i < n; i++) {
		cin >> trees[i];
	}

	sort(trees.begin(), trees.end(), greater<int>());

	int ans = 0;
	for (int i = 0; i < n; i++) {
		if(trees[i] > 10) {
			ans += trees[i] - 10;
		} else {
			break;
		}
	}

	cout << ans << "\n";
    return 0;
}
