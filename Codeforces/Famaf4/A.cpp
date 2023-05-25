#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using str = string;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    vector<int> v(4);
    for (int i = 0; i < 4; i++) cin >> v[i];
    sort(v.begin(), v.end());

    int a, b, c;
    c = v[3] - v[0];
    a = v[1] - c;
    b = v[2] - c;

    cout << a << " " << b << " " << c << "\n";

    return 0;
}
