#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using db = double;
using str = string;

#define sz(x) (int) (x).size()

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int t;
	cin >> t;

	int n;
	vector<int> numbers;
	int input;
	while (t--) {
		cin >> n;
		bool is_ugly = false;
		int sum = 0;
		for (int i = 0; i < n; i++) {
			cin >> input;
			numbers.push_back(input);
			if (sum == numbers[i]) {
				is_ugly = true;
			}
			sum += numbers[i];
		}

		if (!is_ugly) {
			cout << "YES" << "\n";
			for (int i = 0; i < n - 1; i++) {
				cout << numbers[i] << " ";
			}
			cout << numbers[n - 1] << "\n";
		} else {
			sort(numbers.begin(), numbers.end(), greater<int>());
			is_ugly = false;
			sum = 0;
			for (int i = 0; i < n; i++) {
				if (sum == numbers[i]) {
					is_ugly = true;
				}
				sum += numbers[i];
			}

			if (!is_ugly) {
				cout << "YES" << "\n";
				for (int i = 0; i < n - 1; i++) {
					cout << numbers[i] << " ";
				}
				cout << numbers[n - 1] << "\n";
			} else {
				if (numbers[0] == 0) {
					cout << "NO" << "\n";
				} else if (numbers[0] == numbers[1]) {
					for (int j = 2; j < n - 1; j++) {
						if (numbers[0] != numbers[j] && numbers[j] != 0) {
							swap(numbers[1], numbers[j]);
						}
					}
					if (numbers[0] == numbers[1]) {
						cout << "NO" << "\n";
					}
					else {
						cout << "YES" << "\n";
						for (int i = 0; i < n - 1; i++) {
							cout << numbers[i] << " ";
						}
						cout << numbers[n - 1] << "\n";
					}
				}
			}
		}
		numbers.clear();
	}

    return 0;
}
