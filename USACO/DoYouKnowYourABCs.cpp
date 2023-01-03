#include <bits/stdc++.h>
using namespace std;

using ll = long long;

void setIO(string name = "") {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
	if ((int) name.size()) {
		freopen((name + ".in").c_str(), "r", stdin);
		freopen((name + ".out").c_str(), "w", stdout);
	}
}

int main() {
	setIO();

	int numbers[7];
	int a, b, c;

	for (int i = 0; i < 7; i++) {
		cin >> numbers[i];
	}

	sort(begin(numbers), end(numbers));
	a = numbers[0];
	b = numbers[1];
	c = numbers[6] - a - b;

	cout << a << " " << b << " " << c << "\n";
    return 0;
}
