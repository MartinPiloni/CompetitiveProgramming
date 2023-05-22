#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using str = string;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll a, b;
    cin >> a >> b;
    cout << (a % b ? a / b + 1 : a / b) << "\n";
    return 0;
}
