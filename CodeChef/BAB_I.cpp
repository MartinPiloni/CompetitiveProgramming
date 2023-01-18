#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using str = string;

#define sz(x) (int) (x).size()

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int t;
	cin >> t;
	while (t--) {
		int N;
		cin >> N;
		int ans = INT_MAX;
		for (int i = 0; i < N; i++) {
			int input;
			cin >> input;
			ans = min(abs(input), ans);
		}

		cout << ans - 1 << "\n";
	}

    return 0;
}
