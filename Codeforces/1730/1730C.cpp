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
        str s;
        cin >> s;
        vector<int> d(10, -1);
        for (int i = 0; i < sz(s); i++) d[s[i] - '0'] = i;
        for (int i = 1; i < 10; i++) d[i] = max(d[i], d[i - 1]);

        vector<int> ans(sz(s));
        for (int i = 0; i < sz(s); i++) {
            if (s[i] == '0' || s[i] == '9' || d[s[i] - '0' - 1] < i) ans[i] = s[i] - '0';
            else ans[i] = s[i] - '0' + 1;
        }
        sort(all(ans));

        for (int i = 0; i < sz(s); i++) cout << ans[i];
        cout << "\n";
    }

    return 0;
}
