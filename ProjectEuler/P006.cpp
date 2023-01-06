#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using str = string;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	// [n * (n + 1) * (2n + 1)] / 6
	int sum_of_squares = 100 * 101 * 201 / 6;

	// n * (n + 1) / 2
	int square_of_the_sum = pow(100 * 101 / 2, 2);

	cout << square_of_the_sum - sum_of_squares << "\n";
    return 0;
}
