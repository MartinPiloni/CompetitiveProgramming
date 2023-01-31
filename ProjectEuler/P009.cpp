#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using str = string;

#define sz(x) (int) (x).size()

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	for (int i = 1; i < 1000; i++) {
		for (int j = i + 1; j < 1000; j++) {
			for (int k = j + 1; k < 1000; k++) {
				if ((i * i + j * j == k * k) && (i + j + k == 1000)) {
					cout << i * j * k << "\n";
					return 0;
				}
			}
		}
	}

    return 0;
}
