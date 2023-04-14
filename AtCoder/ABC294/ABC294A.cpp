#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using str = string;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    
    int a;
    for (int i = 0; i < n; i++) {
        cin >> a;
        if (a % 2 == 0) cout << a << " ";
    }

    cout << "\n";

    return 0;
}
