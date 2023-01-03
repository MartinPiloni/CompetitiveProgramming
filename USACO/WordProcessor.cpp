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
	setIO("word");

	int n, k;
	cin >> n >> k;

	string word;
	int currentLength = (int) word.size();
	for (int i = 0; i < n; i++) {
		cin >> word;
		currentLength += (int) word.size();
		if (currentLength <= k) {
			if (i != 0) {
				cout << " ";
			}
			cout << word;
		} else {
			cout << "\n" << word;
			currentLength = (int) word.size();
		}
	}

	cout << "\n";
    return 0;
}
