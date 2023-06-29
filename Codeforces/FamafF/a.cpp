#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using str = string;

#define sz(x) int((x).size())

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    str team1, team2 = "", s;
    cin >> team1;
    int cnt_1 = 1, cnt_2 = 0;
    for (int i = 0; i < n - 1; i++) {
        cin >> s;
        if (s == team1) {
            cnt_1++;
        } else {
            if (team2 == "") team2 = s;
            cnt_2++;
        }
    }

    (cnt_1 > cnt_2 ? cout << team1 << "\n" : cout << team2 << "\n");
    return 0;
}
