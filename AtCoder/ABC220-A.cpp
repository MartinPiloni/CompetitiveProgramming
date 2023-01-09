#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using db = double;
using str = string;

#define sz(x) (int) (x).size()

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int a, b , c;
	cin >> a >> b >> c;

	bool e = false;
	for (int i = a; i <= b; i++) {
		if (i % c == 0) {
			cout << i << "\n";
			e = true;
			break;
		}
	}

	if (!e) {
		cout << "-1\n";
	}

    return 0;
}
