#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using str = string;

#define sz(x) (int) (x).size()

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n;
	str s;

	cin >> n >> s;
	for (int i = 0; i < n - 1; i++) {
		if (s[i] == 'n' && s[i + 1] == 'a') {
			s.insert(i + 1, "y");
			n++;
		}
	}

	cout << s << "\n";

    return 0;
}
