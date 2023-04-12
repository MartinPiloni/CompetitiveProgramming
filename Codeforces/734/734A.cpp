#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using str = string;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    str s;
    cin >> s;
    int a = 0, d = 0;
    for (int i = 0; i < n; i++) {
        if(s[i] == 'A') a++;
        else d++;
    }
    
    cout << (a == d ? "Friendship\n" : (a > d ? "Anton\n" : "Danik\n"));
    return 0;
}
