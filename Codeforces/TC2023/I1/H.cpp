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

    ll c[26][26];
    for (int i = 0; i < 26; i++) {
        for (int j = 0; j < 26; j++) {
            cin >> c[i][j];
        }
        c[i][i] = 0;
    }

    int n = 26;
    for (int k = 0; k < n; k++) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                c[i][j] = min(c[i][j], c[i][k] + c[k][j]);
            }
        }
    }

    ll ans = 0, cost;
    str s;
    cin >> s;
    for (int i = 0; i < sz(s) / 2; i++) {
        if (s[i] == s[sz(s) - 1 - i]) continue;

        cost = 1e9;
        for (int j = 0; j < 26; j++) {
            cost = min(cost, c[s[i] - 'a'][j] + c[s[sz(s) - 1 - i] - 'a'][j]);
        }
        ans += cost;
    }
    cout << ans << "\n";

    return 0;
}
