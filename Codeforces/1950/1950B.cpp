#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define fst first
#define snd second
#define sz(x) ((int)x.size())
#define all(x) x.begin(),x.end()

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

        str a = "##";
        str b = "..";

        bool f = true;
        int cnt = 0;
        for (int i = 0; i < 2*n; i++) {
            for (int j = 0; j < n; j++) {
                if (j & 1 && !f || j % 2 == 0 && f) cout << a;
                else cout << b;
            }
            cout << "\n";

            cnt++;
            if (cnt == 2) {
                cnt = 0;
                f = !f;
            }
        }

    }

    return 0;
}
