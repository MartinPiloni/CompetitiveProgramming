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

    int n, c;
    cin >> n >> c;
    
    map<str, ll> freq;
    str s;
    for (int i = 0; i < n; i++) {
        cin >> s;
        for (int j = 0; j < c; j++) {
            if (s[j] == '*') {
                for (int k = 0; k < 26; k++) {
                    s[j] = char('a' + k);
                    freq[s]++;
                }
            }
        }
    }

    ll cnt = 0; 
    for (auto e : freq) {
        cnt = max(cnt, e.snd);
    }

    str ans = "";
    for (auto e : freq) {
        if (e.snd == cnt && ans == "") ans = e.fst;
        else if (e.snd == cnt) ans = min(ans, e.fst);
    }
    cout << ans << " " << cnt << "\n";

    return 0;
}
