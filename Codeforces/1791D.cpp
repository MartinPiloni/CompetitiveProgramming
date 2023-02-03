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
		int n;
		str s;
		cin >> n >> s;

		map<char, int> freq;
		for (int i = 0; i < n; i++) {
			freq[s[i]]++;
		}

		set<char> s1;
		set<char> s2;
		int ans = 0;
		for (int i = 0; i < n; i++) {
			if(s1.insert(s[i]).second == true) {
				ans++;
			}
		}

		for (int i = 0; i < n; i++) {
			s2.insert(s[i]);
			if(freq[s[i]] == 1) {
				freq[s[i]]--;
				s1.erase(s[i]);
			} else {
				freq[s[i]]--;
			}
			ans = max(ans, (int) (s1.size() + s2.size()));
		}

		cout << ans << "\n";
	}

    return 0;
}
