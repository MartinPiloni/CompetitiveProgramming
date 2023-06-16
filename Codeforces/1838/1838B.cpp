#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using str = string;

#define sz(x) int((x).size())

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;

        vector<int> v(n);
        int pos1 = 0, pos2 = 0, posn = 0;
        for (int i = 0; i < n; i++) {
            cin >> v[i];
            if (v[i] == 1) pos1 = i + 1;
            else if (v[i] == 2) pos2 = i + 1;
            else if (v[i] == n) posn = i + 1;
        }

        if ((pos2 < pos1 && pos1 < posn) || (pos1 < pos2 && posn < pos1)) cout << pos1 << " " << posn << "\n";
        else if (pos1 > pos2 && pos1 > posn) {
            (pos2 > posn ? cout << pos2 << " " << posn << "\n" : cout << "1 1\n");
        }
        else if (pos1 < pos2 && pos1 < posn) {
            (pos2 < posn ? cout << pos2 << " " << posn << "\n" : cout << "1 1\n");
        }
    }

    return 0;
}
