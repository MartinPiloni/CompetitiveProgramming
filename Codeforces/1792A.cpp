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
		int n;
		cin >> n;

		vector<int> hp(n);
		for (int i = 0; i < n; i++) {
			cin >> hp[i];
		}

		sort(hp.begin(), hp.end());

		int ans = 0;
		for (int i = 0; i < n; i++) {
			if (hp[i] == hp[i + 1] && hp[i] == 1) {
				ans += 1;
				i++;
			}
			else {
				ans += n - i;
				break;
			}
		}
		cout << ans << "\n";
	}

    return 0;
}
