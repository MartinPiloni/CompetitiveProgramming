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
    setIO("shell");

    int n;
    cin >> n;
    vector<int> pebble = {1, 2, 3};
    vector<int> score(3, 0);

    int a, b, c;
    for (int i = 0; i < n; i++) {
        cin >> a >> b >> c;
        for (int j = 0; j < 3; j++) {
            if (pebble[j] == a) pebble[j] = b;
            else if (pebble[j] == b) pebble[j] = a;
            
            if (c == pebble[j]) score[j]++;
        }
    }

    cout << max(max(score[0], score[1]), score[2]);

    return 0;
}
