#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using str = string;

#define sz(x) (int) (x).size()

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int t;
	cin >> t;
	while (t--) {
		int w, d, h;
		cin >> w >> d >> h;

		int a, b, f, g;
		cin >> a >> b >> f >> g;

		int ans;
		int l, r, fr, ba;
		fr = g + h + b + abs(a - f);
		ba = (d - g) + h + abs(a - f) + (d - b);
		l = ans = f + h + a + abs(g - b);
		r = (w - f) + h + (w - a) + abs(g - b);

		ans = min(fr, min(ba, min(l, r)));
		cout << ans << "\n";
	}

    return 0;
}
