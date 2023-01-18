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

		int odd = 0;
		int even = 0;
		int a = 0;
		for (int i = 0; i < N; i++) {
			cin >> a;
			if (a % 2 == 0) {
				even++;
			} else {
				odd++;
			}
		}

		str ans = "NO";
		if (N % 2 == 0 && odd % 2 == 0) {
			ans = "YES";
		} else if (N % 2 == 1 && odd % 2 == 1) {
			ans = "YES";
		}

		cout << ans << "\n";
	}

    return 0;
}
