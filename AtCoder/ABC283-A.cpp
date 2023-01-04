#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using str = string;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int A, B;
	cin >> A >> B;

	int ans = 1;
	for (int i = 0; i < B; i++) {
		ans *= A;
	}

	cout << ans << "\n";
    return 0;
}
