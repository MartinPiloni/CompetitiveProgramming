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
        str s;
        cin >> n >> s;

        int ans = 0, cnt_o = 0, cnt_c = 0;
        for (int i = 0; i < n; i++) {
            if (s[i] == '(') cnt_o++;
            else cnt_c++;

            if (cnt_c > cnt_o) {
                ans++;
                cnt_c--;
            }
        }

        cout << ans << "\n";
    }
    return 0;
}
