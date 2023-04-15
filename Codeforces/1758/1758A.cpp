#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using str = string;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        str s, r = "";
        cin >> s;
        for (int i = s.size() - 1; i >= 0; i--) {
            r += s[i];
        }

        cout << s + r << "\n";
    }

    return 0;
}
