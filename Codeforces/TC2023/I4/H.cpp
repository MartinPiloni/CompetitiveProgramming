#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define fst first
#define snd second
#define sz(x) ((int)x.size())
#define all(x) x.begin(),x.end()

using ll = long long;
using str = string;

int d[26][26];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    str s, t;
    int n;
    cin >> s >> t >> n;

    if (sz(s) != sz(t)) {cout << "-1\n"; return 0;}

    for (int i = 0; i < 26; i++) {
        for (int j = 0; j < 26; j++) {
            d[i][j] = 1e9;
        }
        d[i][i] = 0;
    }

    char a, b;
    int c;
    for (int i = 0; i < n; i++) {
        cin >> a >> b >> c;
        d[a - 'a'][b - 'a'] = min(d[a - 'a'][b - 'a'], c);
    }

    for (int k = 0; k < 26; ++k) {
        for (int i = 0; i < 26; ++i) {
            for (int j = 0; j < 26; ++j) {
                d[i][j] = min(d[i][j], d[i][k] + d[k][j]); 
            }
        }
    }

    str s_ans;
    int ans = 0, sum, m_c = 0;
    for (int i = 0; i < sz(s); i++) {
        sum = 1e9;
        if (s[i] != t[i]) {
            for (int j = 0; j < 26; j++) {
                if (d[s[i] - 'a'][j] + d[t[i] - 'a'][j] < sum) {
                    sum = d[s[i] - 'a'][j] + d[t[i] - 'a'][j];
                    m_c = 'a' + j;
                }
            }

            s_ans += (char)m_c;
            ans += sum;
        } else {
            s_ans += s[i];
        }
    }

    if (ans > 1e9) cout << "-1\n";
    else {
        cout << ans << "\n";
        cout << s_ans << "\n";
    }

    return 0;
}
