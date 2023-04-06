#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using str = string;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n;
    cin >> n;
    
    vector<ll> stones(n);
    vector<ll> s_stones(n + 1, 0);
    for (int i = 0; i < n; i++) {
        cin >> stones[i];
        s_stones[i + 1] = s_stones[i] + stones[i];
    }

    sort(stones.begin(), stones.end());

    vector<ll> s_sorted(n + 1, 0);
    for (int i = 0; i < n; i++) {
        s_sorted[i + 1] = s_sorted[i] + stones[i];
    }

    int m, type, l, r;
    cin >> m;
    for (int i = 0; i < m; i++) {
        cin >> type >> l >> r;
        if (type == 1) {
            cout << s_stones[r] - s_stones[l - 1] << "\n";
        } else {
            cout << s_sorted[r] - s_sorted[l - 1] << "\n";
        }
    }

    return 0;
}
