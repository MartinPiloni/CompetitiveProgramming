#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using str = string;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n; str s;
    cin >> n >> s;
    
    map<char, int> w;
    for (int i = 0; i < n; i++) {
        w[s[i]]++;
    }

    if (w['A'] > w['T']) cout << "A\n";
    else if (w['A'] < w['T']) cout << "T\n";
    else cout << (s[n - 1] == 'A' ? "T\n" : "A\n");

    return 0;
}
