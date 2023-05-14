#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using str = string;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while(t--) {
        str s;
        cin >> s;

        map<char, int> occ;
        for(int i = 0; i < (int)s.size(); i++) {
            occ[s[i]]++;
        }

        if (occ.size() == 1) cout << "-1\n";
        else cout << s.size() - 1 << "\n";
    }
    return 0;
}
