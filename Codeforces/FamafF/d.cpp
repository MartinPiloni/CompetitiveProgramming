#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using str = string;

#define sz(x) int((x).size())

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;

        vector<ll> v(n);
        for (int i = 0; i < n; i++) {
            cin >> v[i];
        }

        bool ok = true;
        ll cnt = 0;
        for (int i = n - 2; i >= 0; i--) {
            while(v[i] >= v[i + 1]) {
                if(v[i + 1] == 0) {
                    ok = false;
                    cnt = -1;
                    break;
                }
                v[i] /= 2;
                cnt++;
            }

            if (!ok) {
                break;
            }
        }

        cout << cnt << "\n";
    }

    return 0;
}
