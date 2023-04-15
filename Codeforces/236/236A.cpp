#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using str = string;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    str s;
    cin >> s;

    set<char> c;
    for (int i = 0; i < (int) s.size(); i++) {
        c.insert(s[i]);
    }

    cout << (c.size() % 2 == 0 ? "CHAT WITH HER!\n" : "IGNORE HIM!\n");
    return 0;
}
