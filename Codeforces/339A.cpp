#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using str = string;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    str s;
    cin >> s;

    vector<char> a;
    for (int i = 0; i < (int) s.size(); i += 2) {
        a.push_back(s[i]);
    }
    sort(a.begin(), a.end());

    int j = 0;
    for (int i = 0; i < (int) s.size(); i += 2) {
        s[i] = a[j];
        j++;
    }

    for (int i = 0; i < (int) s.size(); i++) {
        cout << s[i];
    }
    cout << "\n";

    return 0;
}
