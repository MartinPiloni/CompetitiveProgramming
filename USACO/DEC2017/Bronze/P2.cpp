#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using str = string;

#define sz(x) int((x).size())

void setIO(string name = "") {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    if ((int) name.size()) {
        freopen((name + ".in").c_str(), "r", stdin);
        freopen((name + ".out").c_str(), "w", stdout);
    }
}

int main() {
    setIO("shuffle");
    int n;
    cin >> n;
    vector<int> shuffle(n), cows(n);
    for (int i = 0; i < n; i++) {cin >> shuffle[i]; shuffle[i]--;}
    for (int i = 0; i < n; i++) cin >> cows[i];

    for (int i = 0; i < n; i++) {
        int n_pos = shuffle[i];
        for (int j = 0; j < 2; j++) {
            n_pos = shuffle[n_pos];
        }

        cout << cows[n_pos] << "\n";
    }

    return 0;
}
