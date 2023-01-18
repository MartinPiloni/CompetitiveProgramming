#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using str = string;

#define sz(x) (int) (x).size()

bool sortbysec(const pair<int,pair<int, int>> &a, const pair<int,pair<int, int>> &b){
	if (a.second.first == b.second.first) {
		return (a.second.second > b.second.second);
	}

	return (a.second.first > b.second.first);
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int t;
	cin >> t;
	while (t--) {
		int N;
		cin >> N;

		vector<pair<int, pair<int, int>>> post(N);
		for (int i = 0; i < N; i++){
			post[i].first = i + 1;
			cin >> post[i].second.first;
		}

		for (int i = 0; i < N; i++) {
			cin >> post[i].second.second;
		}

		sort(post.begin(), post.end(), sortbysec);

		cout << post[0].first << "\n";
	}

    return 0;
}
