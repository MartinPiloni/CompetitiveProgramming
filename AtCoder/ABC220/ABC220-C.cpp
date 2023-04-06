#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using str = string;

#define sz(x) (int) (x).size()

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int N;
	cin >> N;
	vector<ll> a(N);

	ll a_sum = 0;
	for (int i = 0; i < N; i++) {
		cin >> a[i];
		a_sum += a[i];
	}

	ll X;
	cin >> X;

	ll ans = 0;
	ll total_sum = 0;
	ans = (X / a_sum) * N;
	total_sum = a_sum * (X / a_sum);

	for (int i = 0; i < N; i++) {
		total_sum += a[i];
		ans++;
		if (total_sum > X) {
			break;
		}
	}

	cout << ans << "\n";
    return 0;
}
