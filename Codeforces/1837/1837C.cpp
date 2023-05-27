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

        bool f = false;
        for (int i = 0; i < (int)s.size(); i++) {
            if (s[i] == '1' && !f) {
                f = true;
                continue;
            }
            if (s[i] == '?' && !f) {
                s[i] = '0';
                continue;
            }

            if (s[i] == '?' && s[i - 1] != '0' && s[i + 1] != '0') s[i] = '1';
            else if (s[i] == '?') s[i] = '0';
        }   

        cout << s[(int)s.size()] << "\n";
        cout << s << "\n";
    }

    return 0;
}
