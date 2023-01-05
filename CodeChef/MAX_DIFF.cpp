#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using str = string;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int t;
	cin >> t;

	int max_tastiness, sum;
	while (t--) {
	    cin >> max_tastiness >> sum;
	    if (max_tastiness >= sum) {
	        cout << sum << "\n";
	    } else {
	        cout << max_tastiness - (sum - max_tastiness) << "\n";
	    }
	}
	return 0;
}
