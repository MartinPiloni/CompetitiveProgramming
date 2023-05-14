#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using str = string;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    
    vector<int> v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }

    for (int i = 0; i < n - 1; i++) {
        if (v[i] < v[i + 1]) {
            for (int j = v[i]; j < v[i + 1]; j++) {
                cout << j << " ";
            }
        } else {
            for (int j = v[i]; j > v[i + 1]; j--) {
                cout << j << " ";
            }
        }
    }

    cout << v[n - 1] << "\n";
    return 0;
}
