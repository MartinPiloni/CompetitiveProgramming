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
    cout << n << "\n";
    for (int i = 0; i < n; i++) {
        cout << "1" << " \n"[i == n - 1];
    }

    return 0;
}