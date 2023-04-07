#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using str = string;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m, k;
    cin >> n >> m >> k;

    vector<int> d(n), s(m);
    for (int i = 0; i < n; i++) {
        cin >> d[i];
    }
    sort(d.begin(), d.end());

    for (int i = 0; i < m; i++) {
        cin >> s[i];
    }
    sort(s.begin(), s.end());

    int i = 0, j = 0, ans = 0;
    while(i < n && j < m) {
        if (abs(d[i] - s[j]) <= k) {
            i++;
            j++;
            ans++;
        } else {
            if (d[i] < s[j] - k) {
                i++;
            } else if (d[i] > s[j] + k) {
                j++;
            }
        }
    }

    cout << ans << "\n";
    return 0; 
}
