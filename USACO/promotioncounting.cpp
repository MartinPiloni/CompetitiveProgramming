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
	setIO("promote");
	int bronzeBefore, bronzeAfter;
	cin >> bronzeBefore >> bronzeAfter;

	int silverBefore, silverAfter;
	cin >> silverBefore >> silverAfter;

	int goldBefore, goldAfter;
	cin >> goldBefore >> goldAfter;

	int platBefore, platAfter;
	cin >> platBefore >> platAfter;

	int platPromotions = platAfter - platBefore;
	int goldPromotions = goldAfter - goldBefore + platAfter - platBefore;
	int silverPromotions = goldAfter - goldBefore + platAfter - platBefore + silverAfter - silverBefore;

	cout << silverPromotions << "\n" << goldPromotions << "\n" << platPromotions << "\n";

    return 0;
}
