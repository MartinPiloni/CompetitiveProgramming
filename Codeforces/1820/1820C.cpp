#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using str = string;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        
        vector<int> v(n);
        map<int, int> d;
        for (int i = 0; i < n; i++) {
            cin >> v[i];
            d[v[i]]++;
        }

        int mex = 0;
        if (d[0] > 0) {
            mex = prev(d.end())->first + 1;
            for (auto it = d.begin(); it != prev(d.end()); it++) {
                auto j = next(it);
                if (it->first + 1 != j->first) {
                    mex = it->first + 1;
                    break;
                }
            }
        }

        bool ans = false;
        if (mex != n) {
            int l = n, r = -1;
            for (int i = 0; i < n; i++) {
                if (v[i] == mex + 1) {
                    l = min(l, i);
                    r = max(r, i);
                }
            }

            ans = true;
            if (l != n && l != r) {
                for (int i = l + 1; i < r; i++) {
                    if (v[i] < mex && d[v[i]] == 1) {
                        ans = false;
                        break;
                    }
                    d[v[i]]--;
                }
            }
        }

        (ans ? cout << "Yes\n" : cout << "No\n");
    }

    return 0;
}
