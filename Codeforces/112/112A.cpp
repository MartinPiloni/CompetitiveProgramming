#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using str = string;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    str a, b;
    cin >> a >> b;
    bool eq = true;
    for (int i = 0; i < (int) a.size(); i++) {
        a[i] = (char)tolower(a[i]);
        b[i] = (char)tolower(b[i]);
        if(a[i] < b[i]) {
            cout << "-1\n";
            eq = false;
            break;
        }
        else if (a[i] > b[i]) {
            cout << "1\n";
            eq = false;
            break;
        }
    }

    if (eq) cout << "0\n";

    return 0;
}
