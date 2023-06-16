#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using str = string;

#define sz(x) int((x).size())

vector<int> v;

bool can(int m) {
    int cnt = 0, s = v[0];

    for (int i = 0; i < sz(v); i++) {
        // ceil = (a + b - 1) / b
        if ((v[i] - s + 1) / 2 > m) {
            s = v[i];
            cnt++;
        }
    }

    return cnt < 3;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while(t--) {
        int n, in;
        cin >> n;
        for (int i = 0; i < n; i++) {
            cin >> in;
            v.push_back(in);
        }
        sort(v.begin(), v.end());

        int l = 0, r = 1e9, m;
        while (l <= r) {
            m = (l + r) / 2;

            if(can(m)) r = m - 1;
            else l = m + 1;
        }

        cout << l << "\n";
        v.clear();
    }

    return 0;
}
