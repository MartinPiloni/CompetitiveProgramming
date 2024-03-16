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

        vector<vector<bool>> v(sz(s) / 2, vector<bool>(sz(s)));
        for (int i = 0; i < sz(s) / 2; i++) {
            for (int j = 0; j < sz(s); j++) {
                if (j + i + 1 == sz(s)) break;
                v[i][j] = (s[j] == s[j + i + 1] || s[j] == '?' || s[j + i + 1] == '?');
            }
        }

        ll ans = 0;
        for (int i = 0; i < sz(s) / 2; i++) {
            ll sum = 0;
            for (int j = 0; j < sz(s); j++) {
                if (v[i][j] == 1) sum++;
                else sum = 0;

                if (sum == i + 1) {
                    ans = max(ans, sum);
                    break; 
                }
            }
        }

        cout << ans * 2 << "\n";
    }

    return 0;
}
