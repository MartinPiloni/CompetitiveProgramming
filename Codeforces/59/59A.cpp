#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using str = string;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    str s;
    cin >> s;

    int u = 0, l = 0;
    for (int i = 0; i < (int)s.size(); i++) {
        if (s[i] >= 'a') {
            l++;
        } else {
            u++;
        }
    }

    for (int i = 0; i < (int)s.size(); i++) {
        if (l >= u) {
            s[i] = (char)tolower(s[i]);
            cout << s[i];
        } else {
            s[i] = (char)toupper(s[i]);
            cout << s[i];
        }
    }

    cout << "\n";
    return 0;
}
