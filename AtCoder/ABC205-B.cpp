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
	vector<int> arr(n);

	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}

	sort(arr.begin(), arr.end());

	string ans = "Yes\n";
	for (int i = 0; i < n; i++) {
		if (arr[i] != i + 1) {
			ans = "No\n";
			break;
		}
	}

	cout << ans;
    return 0;
}
