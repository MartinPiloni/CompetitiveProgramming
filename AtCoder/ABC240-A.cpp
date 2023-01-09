#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using db = double;
using str = string;

#define sz(x) (int) (x).size()

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int a, b;
	cin >> a >> b;

	if ((a == 1 && b == 10) || a == b - 1) {
		cout << "Yes\n";
	} else {
		cout << "No\n";
	}
    return 0;
}
