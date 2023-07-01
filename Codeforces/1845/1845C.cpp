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
    while(t--) {
        str s, l, r; int m;
        cin >> s >> m >> l >> r;

        vector<bool> b(10, false);
        int ra = r[0] - l[0] + 1, cnt = 0, pw_char = 0;

        for (int i = 0; i < sz(s); i++) {
            if (r[pw_char] >= s[i] && s[i] >= l[pw_char]) {
                if (b[s[i] - '0'] == false) {
                    cnt++;
                    b[s[i] - '0'] = true;
                }

                if (cnt == ra) {
                    cnt = 0;
                    pw_char++;
                    ra = r[pw_char] - l[pw_char] + 1;

                    for (int j = 0; j < 10; j++) b[j] = false;
                }
            }

            if (pw_char == m) {
                break;
            }
        }

        (pw_char == m ? cout << "NO\n" : cout << "YES\n");
    }

    return 0;
}
