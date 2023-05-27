#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using str = string;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    str s, t;
    cin >> n >> s >> t;

    for (int i = 0; i < n; i++) {
        if (s[i] == '0') s[i] = 'o';
        if (t[i] == '0') t[i] = 'o';
        if (s[i] == '1') s[i] = 'l';
        if (t[i] == '1') t[i] = 'l';
    }

    cout << ((s == t) ? "Yes\n" : "No\n");

    return 0;
}
