#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using str = string;

#define sz(x) int((x).size())

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<str> v(n);
    str a; 
    int b, ma = 1e9, j = 0;
    for (int i = 0; i < n; i++) {
        cin >> a >> b;
        if (ma > b) {
            ma = b;
            j = i;
        }

        v[i] = a;
    }

    for (int i = j; i < n; i++) cout << v[i] << "\n";
    for (int i = 0; i < j; i++) cout << v[i] << "\n";

    return 0;
}
