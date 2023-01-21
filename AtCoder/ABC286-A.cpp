#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using str = string;

#define sz(x) (int) (x).size()

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n, p, q, r, s;
	cin >> n >> p >> q >> r >> s;

	vector<int> a(n);
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}

	for (int i = p - 1; i < q; i++) {
		swap(a[i], a[r + i - p]);
	}

	for (int i = 0; i < n; i++) {
		cout << a[i] << " \n"[i == n - 1];
	}

    return 0;
}
