#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using str = string;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while(t--) {
        int n;
        str s;
        cin >> n >> s;

        int cnt_o = 0, cnt_c = 0;
        for (int i = 0; i < n; i++) {
            if (s[i] == '(') cnt_o++;
            else if (s[i] == ')') cnt_c++;
        }
    
        if (cnt_o != cnt_c) {
            cout << -1 << "\n";
            continue;
        }

        int cnt = 0, c = 1, j = 0, colors = 1;
        vector<int> color(n);
        for (int i = 0; i < n; i++) {
            if (s[i] == s[j]) cnt++;
            else cnt--;

            if (cnt >= 0) color[i] = c;
            else {
                colors = 2;
                cnt = 1;
                j = i;
                c = (c == 1 ? 2 : 1);
                color[i] = c;
            }
        }

        reverse(s.begin(), s.end());
        cnt = 0;
        int c_r = 1, r_colors = 1;
        vector<int> color_r(n);
        j = 0;
        for (int i = 0; i < n; i++) {
            if (s[i] == s[j]) cnt++;
            else cnt--;

            if (cnt >= 0) color_r[i] = c_r;
            else {
                r_colors = 2;
                cnt = 1;
                j = i;
                c_r = (c_r == 1 ? 2 : 1);
                color_r[i] = c_r;
            }
        }

        cout << min(colors, r_colors) << "\n";
        if (colors <= r_colors) {
            for (int i = 0; i < n; i++) {
                cout << color[i] << " \n"[i == n - 1];
            }
        } else {
            for (int i = n - 1; i >= 0; i--) {
                cout << color_r[i] << " \n"[i == 0];
            }
        }
    }
    return 0;
}
