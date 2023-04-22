#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using str = string;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, b = 0;
    cin >> n;
    str s;
    cin >> s;
    bool ans = true;
    
    for (int i = 0; i < n; i++) {
        if (s[i] == '|') {
            b++;
        } else if (s[i] == '*' && b != 1) {
            ans = false;
            break;
        }
    }

    (ans ? cout << "in\n" : cout << "out\n");
    return 0;
}
