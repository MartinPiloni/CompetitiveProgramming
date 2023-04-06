#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using str = string;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int N;
	cin >> N;

	int arr[N];
	for (int i = 0; i < N; i++) {
		cin >> arr[i];
	}

	int Q;
	cin >> Q;

	int q_type;
	int index;

	for (int i = 0; i < Q; i++) {
		cin >> q_type;

		if (q_type == 1) {
			cin >> index;
			cin >> arr[index - 1];
		}
		else if (q_type == 2) {
			cin >> index;
			cout << arr[index - 1] << "\n";
		}
	}


    return 0;
}
